//
// Created by Ariana Astorga Vega on 10/7/26.
//

#pragma once
template <typename T>
class List{
    public:
    virtual void addAnywhere(int position, T* value) = 0;
    virtual void deleteAnywhere(int position) = 0;
    virtual void reverse() = 0;
    virtual void concat(List<T>* other) = 0;

private:
};

