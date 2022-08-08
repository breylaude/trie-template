//
// Created by Ignas Laude on 5/30/21.
//

#ifndef TRIEMPLATE_TRIEMPLATE_H
#define TRIEMPLATE_TRIEMPLATE_H

#include <algorithm>
#include <string>
#include <stack>
#include "Iterator.h"

/**
 * -1 if cur node's key is equivalent to input,
 *      ie you have found the end of the node-sequence, and are now at the node that will hold the value for the article
 *
 * 0 through S-1 if new node to check,
 *      ie the return is the index for the next child to move onto
 *
 * -2 if not found
 */
template <typename K, typename T, uint32_t S>
class BinTrie_Indexer {
public:
    // called when not inserting
    int32_t operator()(K& input, const Node<K,T,S>* node) {
        if (input == node->key_) {
            return (node->value_) ? -1 : -2;
        }
        return (input < node->key_) ? 0 : 1;
    }

    // called when inserting
    int32_t operator()(K& input, Node<K,T,S>* &node) {

        if (node == nullptr) {
            node = new Node<K, T, S>(input);
            return -1;
        }
        else if (input == node->key_)
            return -1;
        else
            return (input < node->key_) ? 0 : 1;
    }
};

// forward declaration
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
class triemplate;

/**
 *
 */
template<typename K, typename T, uint32_t S, typename Indexer>
class BinTrie_Eraser {
public:
    void operator()(Node<K,T,S>* &ancestor, Node<K,T,S>* &descendant, triemplate<K,T,S,Indexer,BinTrie_Eraser<K,T,S,Indexer>> &trie) {

        std::stack<std::pair<K,T>> stk;
        mergeStack(stk, getStack(descendant->child_.at(0).get()));
        mergeStack(stk, getStack(descendant->child_.at(1).get()));

        Node<K,T,S>* par(descendant->parent_);
        if (ancestor == descendant) {
            par->child_.at(findChildsIndex(descendant)).reset();
            descendant = par;
            ancestor = descendant;
        }
        else {
            par->child_.at(findChildsIndex(descendant)).reset();
            descendant = par;
        }

        while (!stk.empty()) {
            trie.insertOrAssign(stk.top());
            stk.pop();
        }
    }

    static uint32_t findChildsIndex(Node<K,T,S>* &child) {
        assert(child->parent_ != nullptr);
        Node<K,T,S>* parptr(child->parent_);
        for (uint32_t i(0); i < S; ++i) {
            if (parptr->child_.at(i).get() == child)
                return i;
        }
        throw std::domain_error("child's index not found -- potential linking problem");
    }

    static std::stack<std::pair<K,T>> getStack(Node<K,T,S>* node) {
        std::stack<std::pair<K,T>> stk;
        if (node != nullptr) {
            stk.push(std::pair<K, T>(node->key_, *node->value_));
            mergeStack(stk,getStack(node->child_.at(0).get()));
            mergeStack(stk,getStack(node->child_.at(1).get()));
        }
        return stk;
    }

    static std::stack<std::pair<K,T>> mergeStack(std::stack<std::pair<K,T>> &merged, std::stack<std::pair<K,T>> other) {
        while (!other.empty()) {
            merged.push(other.top());
            other.pop();
        }
        return merged;
    }
};

template <typename K, typename T, uint32_t S = 2, typename Indexer = BinTrie_Indexer<K,T,S>, typename Eraser = BinTrie_Eraser<K,T,S,Indexer>>
class triemplate {
public:

    typedef K                                       key_type;
    typedef T                                       mapped_type;
    typedef Indexer                                 key_indexer;
    typedef Eraser                                  key_eraser;
    typedef Iterator<key_type,mapped_type,S>        iterator;
    typedef Node<key_type,mapped_type,S>            Node;

    //default ctor
    explicit triemplate();

    // copy ctor
    explicit triemplate(const triemplate& rhs);
    explicit triemplate(const triemplate&& rhs);

    //DTOR
    ~triemplate();

    //assignment op
    //region //operator=()
    triemplate &operator=(const triemplate& rhs);
    triemplate &operator=(const triemplate&& rhs);
    //endregion

//////////////////////////////////////////////////////
//// CAPACITY

    /**
     * checks whether the container is empty
     * @return - true if empty, false otherwise
     */
    bool empty() const noexcept;

    /**
     * returns the number of articles in trie
     * @return - unsigned int for number of elements in trie
     */
    uint32_t size() const noexcept;

//////////////////////////////////////////////////////
//// MODIFIERS

    /**
     * clears the contents, ie if not already empty, deletes the contents of the trie
     */
    void clear() noexcept;

    /**
     * inserts article if not already present, and adds value at end of article's sequence
     * @param article - the key used to find value's target
     * @param value - the value being stored at element
     * @return - an iterator to the node that holds value
     */
     //region //insert();
    iterator insertOrAssign(std::pair<key_type,mapped_type>& p, Node* ancestor = nullptr);
    iterator insertOrAssign(std::pair<key_type,mapped_type>&& p, Node* ancestor = nullptr);

    iterator insertOrAssign(key_type article, mapped_type& value, Node* ancestor = nullptr);
    iterator insertOrAssign(key_type article, mapped_type&& value, Node* ancestor = nullptr);
    //endregion

    /**
     * erases articles within trie
     * @param article - the key being deleted
     */
     //region //erase();
    void erase(key_type article,Node* ancestor = nullptr);

     // erase article with descendant as end of its node sequence, must stop at ancestor
    void erase(Node* &descendant, Node* ancestor = nullptr);
     //endregion

    /**
     * swaps the contents
     * @param rhs - the container to exchange the contents with
     */
    void swap(triemplate& rhs) noexcept;

//////////////////////////////////////////////////////
//// LOOKUPS

    /**
     * finds the node that holds the values for the article
     * @param article - the article being searched for
     * @return - an iterator at the last node in sequence for the article, else returns .end()
     */
    iterator find(key_type article);

    /**
     * finds the last viable node in sequence for the article. The returned pair contains, first, a boolean which holds
     * the same value as the contains() function returns, and second, an iterator at the last viable node in sequence.
     *
     * Example: given 'LOOKUP' was inserted in a BTrie, scout('LOOK') will return pair<false,node('K')>, and
     * scout('LOOKUP') will return pair<true,node('P')> (where node(N) represents the node at N letter in the node
     * sequence)
     *
     * @param article - the article being searched for
     * @return - returns a pair of a boolean and an iterator at the last viable node for the article's node sequence
     */
    std::pair<bool,iterator> scout(key_type article,Node* ancestor = nullptr);

    /**
     * checks if the container contains element
     * @param element - the key being searched for
     * @return - true if in container, else false
     */
    bool contains(key_type article,Node* ancestor = nullptr);

//////////////////////////////////////////////////////
//// COMPARERS

    bool operator==(const triemplate& rhs) const;
    bool operator!=(const triemplate& rhs) const;

//////////////////////////////////////////////////////
//// ITERATORS

    iterator begin();

    iterator end();

private:

//////////////////////////////////////////////////////
//// VARIABLES

    uint32_t numberArticles_;

    key_indexer indexer_;

    key_eraser eraser_;

    Node* root_;

//////////////////////////////////////////////////////
//// PRIVATE HELPER METHODS

    static std::pair<bool, iterator> scout_helper(key_type& key, const Node* curNode, key_indexer& indexer);

    static iterator insert_helper(Node* &curNode, key_type& article, mapped_type& value, key_indexer& indexer);
    static iterator insert_helper(Node* &&curNode, key_type& article, mapped_type& value, key_indexer& indexer);

    void checkIterPtr_helper(Node* &ptr);

};

#include "../src/triemplate.cpp"

#endif //TRIEMPLATE_TRIEMPLATE_H
