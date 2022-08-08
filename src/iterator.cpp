//
// Created by Ignas Laude on 5/30/21.
//

#ifndef TRIEMPLATE_ITERATOR_CPP
#define TRIEMPLATE_ITERATOR_CPP

#include "../include/Iterator.h"

template<typename K, typename T, uint32_t S>
Iterator<K, T, S>::Iterator(Node<K, T, S> &currentNode, int32_t previousIndex) : curNode_(&currentNode), prevIndex_(previousIndex) {
}

template<typename K, typename T, uint32_t S>
Iterator<K, T, S>::Iterator(const Iterator &rhs) : curNode_((rhs.curNode_)), prevIndex_(rhs.prevIndex_) {
}

template<typename K, typename T, uint32_t S>
Node<K, T, S> &Iterator<K, T, S>::operator*() {
    return *curNode_;
}

template<typename K, typename T, uint32_t S>
Node<K, T, S>* Iterator<K, T, S>::operator->() {
    return curNode_;
}

template<typename K, typename T, uint32_t S>
Node<K, T, S> *&Iterator<K, T, S>::get() {
    return curNode_;
}

template<typename K, typename T, uint32_t S>
K &Iterator<K, T, S>::first() {
    return curNode_->key_;
}

template<typename K, typename T, uint32_t S>
T &Iterator<K, T, S>::second() {
    return *(curNode_->value_);
}

template<typename K, typename T, uint32_t S>
bool Iterator<K, T, S>::isArticleEnd() {
    return bool(curNode_->value_);
}

template<typename K, typename T, uint32_t S>
int32_t &Iterator<K, T, S>::getIndex() {
    return prevIndex_;
}

template<typename K, typename T, uint32_t S>
void Iterator<K, T, S>::swap(Iterator &rhs) {
    if (this != &rhs) {
        std::swap(curNode_, rhs.curNode_);
        std::swap(prevIndex_, rhs.prevIndex_);
    }
}

template<typename K, typename T, uint32_t S>
Iterator<K,T,S> &Iterator<K, T, S>::operator=(Iterator &rhs) {
    if (this != &rhs) {
        Iterator ph(rhs);
        swap(rhs);
    }
    return *this;
}

template<typename K, typename T, uint32_t S>
Iterator<K,T,S> &Iterator<K, T, S>::operator=(Iterator &&rhs) {
    return *this = rhs;
}

template<typename K, typename T, uint32_t S>
Iterator<K,T,S> &Iterator<K, T, S>::moveUp() {
    // todo deal with root? if it goes wrong then it will assert for you
    int32_t index = findChildsIndex(*(curNode_->parent_), *curNode_);
    assert(index > -1 && index < S);
    Iterator ph(*curNode_->parent_, index);
    swap(ph);
    return *this;
}

template<typename K, typename T, uint32_t S>
Iterator<K,T,S> &Iterator<K, T, S>::operator++() {

    // ensure curnode doesn't point to null
    assert (curNode_ != nullptr);

    // find next valid child to go to
    int32_t nextIndex = findValidSucceedingChildIndex(*curNode_,prevIndex_);

    // instantiate common iterator
    // if valid child
    Iterator nextIter(*this); // instantiate an iterator
    if (nextIndex < S) {
        nextIter = Iterator(*curNode_->child_.at(nextIndex), -1);
    }
    // at this point: no valid child to go to next

    // if parent not null, go up to get to next node
    else if (curNode_->parent_ != nullptr) {
        // find curNode's index as child in parent's children
        int parentsPrevIndex = findChildsIndex(*(curNode_->parent_), *curNode_);
        nextIter = Iterator(*curNode_->parent_, parentsPrevIndex);
        ++nextIter;
    }

    // else return end iterator
    else {
        nextIter = Iterator(*curNode_, S-1);
    }

    swap(nextIter);
    return *this;
}

template<typename K, typename T, uint32_t S>
Iterator<K,T,S> Iterator<K, T, S>::operator++(int) {
    Iterator ph(*this);
    ++(*this);
    return ph;
}

template<typename K, typename T, uint32_t S>
bool Iterator<K, T, S>::operator==(const Iterator &rhs) const {
    return this == &rhs || curNode_ == rhs.curNode_;
}

template<typename K, typename T, uint32_t S>
bool Iterator<K, T, S>::operator!=(const Iterator &rhs) const {
    return !(*this == rhs);
}

template<typename K, typename T, uint32_t S>
int32_t Iterator<K, T, S>::findValidSucceedingChildIndex(const Node<K, T, S> &parent, int32_t previousIndex) {
    int32_t wlkr(previousIndex + 1);
    while (wlkr < S) {
        if (parent.child_.at(wlkr).get() != nullptr)
            break;
        ++wlkr;
    }
    return wlkr;
}

template<typename K, typename T, uint32_t S>
int32_t Iterator<K, T, S>::findChildsIndex(const Node<K, T, S> &parent, const Node<K, T, S> &child) {
    for (uint32_t i(0); i < S; ++i) {
        if (parent.child_.at(i).get() == &child)
            return i;
    }
    return -1;
}

#endif // TRIEMPLATE_ITERATOR_CPP
