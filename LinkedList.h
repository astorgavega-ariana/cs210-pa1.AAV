//
// Created by Ariana Astorga Vega on 10/7/26.
//

#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
    public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addFront(T* value) override {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        ++size;
    }
    void deleteFront() override {
        if (head == nullptr) {
            std::cout<<"Game is empty"<<std::endl;
            return;
        }
        Node<T>* doomed = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete doomed->data;
        delete doomed;
        --size;
    }
    bool search(T* value) const override {
        Node<T>* current = head;
        while (current != nullptr) {
            if (*current->data == *value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void print() const override {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout<<current->data<< ",";
            current = current->next;
        }
        std::cout<<std::endl;
    }
    ~LinkedList() override {
        while (head != nullptr) {
            Node<T>* doomed = head;
            head = head->next;
            delete doomed->next;
            delete doomed;
        }
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};