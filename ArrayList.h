//
// Created by Ariana Astorga Vega on 10/7/26.
//

#pragma once
#include <iostream>
#include <ostream>

#include "List.h"

template <typename T>
class ArrayList : public List<T> {
    public:
    ArrayList() : size(0){}

    void addFront(T* value) override {
        if (size >= CAPACITY) {
            std::cout << "Game is full" << std::endl;
            return;
        }
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }
    void deleteFront() override {
        if (size == 0) {
            std::cout << "Game is empty" << std::endl;
            return;
        }
        delete data[0];
        for (int i = 0; i < size - 1, i++;) {
            data[i] = data[i + 1];
        }
        data[size - 1] = nullptr;
        size--;
    }
    bool search(T* value) const override {
        for (int i = 0; i < size; i++) {
            if (*data[i] == *value) {
                return true;
            }
        }
        return false;
    }
    void print() const override {
        for (int i = 0; i < size; i++) {
            std::cout << *data[i] << ",";
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override{
        if (position < 0 || position >= size) {
            std::cout << "Not doable" << std::endl;
            return;
        }
        if (size >= CAPACITY) {
            std::cout << "Game is full" << std::endl;
            return;
        }
        for (int i = size; i > position; i--) {
            data[i] = data[i - 1];
        }
        data[position] = value;
        size++;
    }
    void deleteAnywhere(int position) override{
        if (position < 0 || position >= size) {
            std::cout << "Not doable" << std::endl;
            return;
        }
        delete data[position];
        for (int i = position; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        data[size - 1] = nullptr;
        size--;
    }

    void reverse() override{
        for (int i = 0; i < size / 2; i++) {
            T* temp = data[i];
            data[i] = data[size - 1 - i];
            data[size - 1 - i] = temp;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* otherList = dynamic_cast<ArrayList<T>* >(other);
        if (otherList == nullptr) {
            std::cout << "Cant concat different list types" << std::endl;
            return;
        }
        if (size + otherList->size > CAPACITY) {
            std::cout << "Game is full" << std::endl;
            return;
        }
        int gameSize = size;
        for (int i = 0; i < otherList->size; i++) {
            data[gameSize + i] = otherList->data[i];
            otherList->data[i] = nullptr;
        }
        size += otherList->size;
        otherList->size = 0;
    }

    ~ArrayList() override {
        for (int i = 0; i<size; i++) {
            delete data[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data[CAPACITY];
    int size;

};