//
// Created by Ariana Astorga Vega on 10/7/26.
//

#pragma once
template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;
    explicit Node(T* value) : data(value), next(nullptr) {}
};