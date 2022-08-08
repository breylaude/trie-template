//
// Created by Ignas Laude on 5/30/21.
//

#ifndef TRIEMPLATE_NODE_H
#define TRIEMPLATE_NODE_H

#include <optional>

template<typename K, typename T, uint32_t S>
struct Node {

    explicit Node(Node* parent = nullptr);

    explicit Node(K key, Node* parent = nullptr);

    explicit Node(const Node& rhs);

    ~Node() = default;

    // swaps all elements
    void swap(Node &rhs) noexcept;

    Node& operator=(const Node& rhs);
    Node& operator=(const Node&& rhs);

    bool operator==(const Node& rhs);

    bool operator!=(const Node& rhs);

    K key_;

    Node* parent_;

    std::optional<T> value_;

    std::unique_ptr<Node<K,T,S>> child_[S];

};

#include "../src/Node.cpp"

#endif //TRIEMPLATE_NODE_H
