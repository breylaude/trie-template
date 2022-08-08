//
// Created by Ignas Laude on 5/30/21.
//

#ifndef TRIEMPLATE_NODE_CPP
#define TRIEMPLATE_NODE_CPP

#include "../include/Node.h"

template<typename K, typename T, uint32_t S>
Node<K, T, S>::Node(Node *parent) : parent_(parent), value_(std::nullopt), child_() {}

template<typename K, typename T, uint32_t S>
Node<K, T, S>::Node(K key, Node* parent) : key_(key), parent_(parent), value_(std::nullopt), child_() {
}

template<typename K, typename T, uint32_t S>
Node<K, T, S>::Node(const Node &rhs) : parent_(nullptr), key_(rhs.key_), value_(rhs.value_), child_() {
    // assign children
    for (uint32_t i(0); i < S; ++i) {
        if (rhs.child_[i].get() != nullptr) {
            child_[i] = std::make_unique<Node<K,T,S>>(*(rhs.child_[i]));
            child_[i]->parent_ = this;
        }
    }
}

template<typename K, typename T, uint32_t S>
void Node<K, T, S>::swap(Node &rhs) noexcept {
    if (this != &rhs) {
        std::swap(parent_, rhs.parent_);
        std::swap(key_, rhs.key_);
        std::swap(value_, rhs.value_);
        std::swap(child_, rhs.child_);
    }
}

template<typename K, typename T, uint32_t S>
Node<K,T,S> &Node<K, T, S>::operator=(const Node &rhs) {
    if (this != &rhs) {
        Node ph(rhs);
        swap(ph);
    }
    return *this;
}

template<typename K, typename T, uint32_t S>
Node<K,T,S> &Node<K, T, S>::operator=(const Node &&rhs) {
    return *this = rhs;
}

template<typename K, typename T, uint32_t S>
bool Node<K, T, S>::operator==(const Node &rhs) {
    //todo should this include comparing child? NO
    if (this == &rhs)
        return true;

    if ((key_ == rhs.key_) && (value_ == rhs.value_)) {
        for (uint32_t i(0); i < S; ++i) {
            if (child_.at(i).get() == nullptr) {
                if (rhs.child_.at(i).get() != nullptr)
                    return false;
            }
            else {
                if (rhs.child_.at(i).get() == nullptr)
                    return false;

                if (*(child_.at(i)) != *(rhs.child_.at(i)))
                    return false;
            }
        }
        return true;
    }
    return false;
}

template<typename K, typename T, uint32_t S>
bool Node<K, T, S>::operator!=(const Node &rhs) {
    return !(*this == rhs);
}

#endif // TRIEMPLATE_NODE_CPP
