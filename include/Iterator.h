//
// Created by Ignas Laude on 5/30/21.
//

#ifndef TRIEMPLATE_ITERATOR_H
#define TRIEMPLATE_ITERATOR_H

#include "Node.h"
#include <list>

/**
 * @class Iterator
 * @brief bi-directional Iterator class, iterates through the nodes of a trie
 *
 * @tparam K - the key_type of the trie
 * @tparam T - the mapped_type of the trie
 * @tparam S - the number of child nodes for composites
 */
template <typename K, typename T, uint32_t S>
class Iterator  {
public:
    using iterator_category     = std::forward_iterator_tag;
    using value_type            = Node<K,T,S>;
    using difference_type       = std::ptrdiff_t;
    using pointer               = Node<K,T,S>*;
    using reference             = Node<K,T,S>&;

    Iterator(Node<K,T,S> &currentNode, int32_t previousIndex = -1);

    // copy ctor
    Iterator(const Iterator &rhs);

    // dtor
    ~Iterator() = default;


    /////////////////////////////////////////////////////////////////////////
    /// ACCESSORS

    /**
     * @return the node being pointed to by this
     */
    Node<K,T,S> &operator*();

    /**
     * @return a pointer to the node pointed to by this
     */
    Node<K,T,S>* operator->();

    /**
     * @return a pointer to the node pointed to by this
     */
    Node<K,T,S>* &get();

    /**
     * @return the key
     */
    K &first();

    /**
     * @return the value
     */
    T &second();

    /**
     * @return true if an end to an article, false otherwise
     */
    bool isArticleEnd();

    /**
     * @return the prevIndex of the iterator
     */
    int32_t& getIndex();

    /**
     * looks for child node within parent's vector of children and returns the child's index.  if not found returns -1
     * @param parent - the parent whos vector of children is being searched through
     * @param child - the child that's being searched for
     * @return - the index of the child or -1 if not found
     */
    static int32_t findChildsIndex(const Node<K,T,S> &parent, const Node<K,T,S> &child);


    /////////////////////////////////////////////////////////////////////////
    /// MODIFIERS

    /**
     * swaps all values between *this and rhs
     * @param rhs the object being swapped with *this
     */
    void swap(Iterator& rhs);

    /**
     * assignment operator
     * @param rhs the object *this is being assigned to
     * @return *this after assignment
     */
    Iterator &operator=(Iterator &rhs);
    Iterator &operator=(Iterator &&rhs);

    /**
     * turns curNode into its parent, from curNode
     * @return moved Iterator
     */
    Iterator &moveUp();

    /**
     * prefix increments Iterator to next value
     * @return this after increment
     */
    Iterator &operator++();

    /**
     * postfix increments Iterator to next value
     * @param rhs - the Iterator being on the right side of the ++ operator
     * @return the Iterator prior to the increment
     */
    Iterator operator++(int);

    /**
     * prefix decrements the Iterator
     * @return the decremented Iterator
     */
    // Iterator &operator--();

    /**
     * postfix decrements the Iterator
     * @param rhs - the Iterator being on the right side of the -- operator
     * @return
     */
    // Iterator operator--(int);


    /////////////////////////////////////////////////////////////////////////
    /// COMPARERS

    /**
     * compares equivalence
     * @param rhs - the other Iterator being compared to this
     * @return
     */
    bool operator==(const Iterator &rhs) const;

    /**
     * compares equivalence
     * @param rhs - the other Iterator being compared to this
     * @return
     */
    bool operator!=(const Iterator &rhs) const;

private:
    // current node being looked at
    Node<K,T,S>* curNode_;

    // the previous index
    int32_t prevIndex_;

    /**
     * looks for the next valid child after prevIndex and returns its index number, if none available then returns S
     * @return index of next valid child after prev, else S if none
     */
    static int32_t findValidSucceedingChildIndex(const Node<K,T,S> &parent, int32_t previousIndex);
};

#include "../src/Iterator.cpp"

#endif //TRIEMPLATE_ITERATOR_H
