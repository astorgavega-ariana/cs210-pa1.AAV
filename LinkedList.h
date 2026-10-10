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
            std::cout<<*current->data<< ",";
            current = current->next;
        }
        std::cout<<std::endl;
    }
    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_){
            std::cout<<"Not doable"<<std::endl;
            return;
        }
        if (position == 0 ) {
            addFront(value);
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;

        for (int i = 0; i < position - 1; i++ ) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = current;
        }
        size++;
    }
    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size) {
            std::cout<<"Not doable"<<std::endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }
        Node<T>* previous = head;
        for (int i = 0; i < position - 1; i++) {
            previous = previous->next;
        }
        Node<T>* doomed = previous->next;
        previous->next = doomed->next;
        if (doomed == tail) {
            tail = previous;
        }
        delete doomed->data;
        delete doomed;
        size--;
    }

    void reverse() override {
        Node<T>* previous = nullptr;
        Node<T>* current = head;
        tail = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = current;
    }

    void concat(List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>* >(other);
        if (otherList == nullptr) {
            std::cout<<"Cant concat different list types"<<std::endl;
            return;
        }
        if (otherList->size == 0) {
            return;
        }
        else {
            tail ->next = otherList->head;
            tail = otherList->tail;
        }
        size += otherList->size;
        otherList->head = nullptr;
        otherList->tail = nullptr;
        otherList->size = 0;
    }


    ~LinkedList() override {
        while (head != nullptr) {
            Node<T>* doomed = head;
            head = head->next;
            delete doomed->data;
            delete doomed;
        }
        tail = nullptr;
        size = 0;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};