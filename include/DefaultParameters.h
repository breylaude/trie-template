//
// Created by Ignas Laude on 6/20/21.
//

#ifndef TRIEMPLATE_DEFAULTPARAMETERS_H
#define TRIEMPLATE_DEFAULTPARAMETERS_H

#include "triemplate.h"

// assume all upper-case letters
template<typename T>
class Radix_Indexer {
public:
    // called when not inserting
    int32_t operator()(std::string& input, const Node<std::string,T,26>* node) {
        // assume never nullptr
        int16_t diff(findDeviation(input,node->key_));

        if (diff == input.size()) { // if found all of key
            input = "";
            // if node key is longer
            return (diff != node->key_.size()) ? -2 : -1;
        }
        else if (diff == node->key_.size()) { // move on to next child
            input = input.substr(diff);
            return findChildIndex(input.at(0));
        }
        return -2;
    }

    // called when inserting
    int32_t operator()(std::string& input, Node<std::string,T,26>* &node) {
        // if nullptr, found your node!!
        if (node == nullptr) {
            node = new Node<std::string,T,26>(input);
            input = "";
            return -1;
        }

        int16_t diff(findDeviation(input,node->key_)); // find the first index of difference between strings

        if (diff == 0) {
            if (node->key_.empty())
                input = input.substr(diff);
            else // legit just different beginning letters... todo assume first child node of root?
                breakUpNode(*node,diff);
        }
        else if (diff == input.size()) { // if found all of key
            input = "";
            if (diff != node->key_.size()) { // node key is larger, must break up node
                breakUpNode(*node, diff);
            }
            // if node key is longer
            return -1;
        }
        else if (diff == node->key_.size()) { // node key is smaller than input, move on to next child
            input = input.substr(diff);
        }
        else { // the difference is in the middle of both strings!!! tough
            breakUpNode(*node, diff);
            input = input.substr(diff);
        }

        return findChildIndex(input.at(0));
    }

    // returns the index at deviation
    static int16_t findDeviation(const std::string& input, const std::string& nodeString) {
        for (uint32_t i(0); i < input.length(); ++i) {
            // if input length longer than nodeString length or strings not equal to eachother at i
            if (i >= nodeString.length() || input.at(i) != nodeString.at(i))
                return i;
        }
        return input.length();
    }

    static int16_t findChildIndex(const char16_t& letter) {
        return letter - 'A';
    }

    static void breakUpNode(Node<std::string,T,26>& node, int16_t diff) {
        Node<std::string,T,26> *ph_copy(new Node<std::string,T,26>(node)), *def(new Node<std::string,T,26>(node.parent_)); // make a copy and default

        node.swap(*def); // give default vals
        node.key_ = ph_copy->key_.substr(0,diff); // reassign with prefix of key
        ph_copy->key_ = ph_copy->key_.substr(diff); // reassign with postfix of key

        node.child_.at(findChildIndex(ph_copy->key_.at(0))).reset(ph_copy);
        ph_copy->parent_ = &node;
    }
};

template<typename T>
class Radix_Eraser {
public:
    void operator()(Node<std::string,T,26>* &ancestor, Node<std::string,T,26>* &descendant, triemplate<std::string,T,26,Radix_Indexer<T>,Radix_Eraser<T>> &trie) {
        assert(descendant != trie.end().get());
        uint16_t cnt(childCount(*descendant));
        if (cnt == 0) { // if child empty
            handleDelete(ancestor,descendant,trie);

            if (descendant != trie.end().get()) // handle descendant now that you've moved it, consider it the parent
                handleCompacting(ancestor,descendant,trie);
        }
        else { // has children

            // empty out value so compacting will work
            descendant->value_ = std::nullopt;

            // handle potential children
            handleCompacting(ancestor,descendant,trie);

            if (!descendant->value_ && childCount(*descendant) < 2)
                handleDelete(ancestor,descendant,trie);

            // handle parent now that you've changed descendant
            if (descendant != trie.end().get())
                handleCompacting(ancestor,descendant->parent_,trie);
        }
    }

    static uint32_t findChildsIndex(Node<std::string,T,26> &child) {
        assert(child.parent_ != nullptr);
        Node<std::string,T,26>* parptr(child.parent_);
        for (uint32_t i(0); i < 26; ++i) {
            if (parptr->child_.at(i).get() == &child)
                return i;
        }
        throw std::domain_error("child's index not found -- potential linking problem");
    }

    static void handleCompacting(Node<std::string,T,26>* &ancestor, Node<std::string,T,26>* &parent, triemplate<std::string,T,26,Radix_Indexer<T>,Radix_Eraser<T>> &trie) {
        // if doesn't have assigned value
        if (!parent->value_) {
            uint16_t cnt(childCount(*parent));

            if (cnt == 0) { // if child empty
                // rollback delete and compact delete
                handleDelete(ancestor,parent,trie);
                handleCompacting(ancestor,parent,trie);
            }
            else if (cnt == 1) { // if only one child
                for (uint16_t i(0); i < 26; ++i) {
                    if (parent->child_.at(i) != nullptr) {

                        // merge
                        Node<std::string,T,26>* ph_copy(new Node<std::string,T,26>(*parent->child_.at(i).get()));
                        ph_copy->key_ = parent->key_ + ph_copy->key_;
                        ph_copy->parent_ = parent->parent_;

                        parent->swap(*ph_copy);
                        break;
                    }
                }
            }
        }
    }

    static uint16_t childCount(Node<std::string,T,26>& node) {
        uint16_t cnt;
        for (uint16_t i(0); i < 26; ++i) {
            if (node.child_.at(i) != nullptr)
                ++cnt;
        }
        return cnt;
    }

    static void handleDelete(Node<std::string,T,26>* &ancestor, Node<std::string,T,26>* &descendant, triemplate<std::string,T,26,Radix_Indexer<T>,Radix_Eraser<T>> &trie) {
        if (descendant != trie.end().get()) {
            uint16_t childIndex(findChildsIndex(*descendant)); // find the index of descendant in parents child
            if (ancestor == descendant)
                ancestor = descendant->parent_;
            descendant = descendant->parent_;
            descendant->child_.at(childIndex).reset();
        }
    }
};

#endif //TRIEMPLATE_DEFAULTPARAMETERS_H
