#pragma once

//
// Created by retek on 2023. 09. 10..
//

#ifndef TEXTRPGGAME_DARRAY_H
#define TEXTRPGGAME_DARRAY_H

#include <cstddef>

template<typename T>
class dArray {
private:
    unsigned cap;
    unsigned initialCap;
    unsigned nrOfElements;
    T** arr;

    void expand();
    void initialize(unsigned from);

public:
    explicit dArray(unsigned size = 5);
    dArray(const dArray& obj);
    ~dArray();

    T& operator[] (unsigned index);
    void operator= (const dArray& obj);

    unsigned maxCap();
    unsigned size();
    void push(T element);
    void remove(unsigned index, bool ordered = false);
};

template<typename T>
dArray<T>::dArray(unsigned size) {
    this->initialCap = size;
    this->cap = size;
    this->nrOfElements = 0;

    this->arr = new T* [this->cap];

    this->initialize(0);
}

template<typename T>
dArray<T>::dArray(const dArray& obj) {
    this->initialCap = obj.initialCap;
    this->cap = obj.cap;
    this->nrOfElements = obj.nrOfElements;
    this->arr = new T * [this->cap];

    for (int i = 0; i < this->nrOfElements; i++)
    {
        this->arr[i] = new T(*obj.arr[i]);
    }

    this->initialize(0);
}

template<typename T>
dArray<T>::~dArray()
{
    for (size_t i = 0; i < this->nrOfElements; i++)
    {
        delete this->arr[i];
    }
    delete[] arr;
}

template<typename T>
T& dArray<T>::operator[] (const unsigned index)
{
    if (index >= this->nrOfElements)
        throw "OUT OF BOUNDS INDEXING OPERATOR.";

    return *this->arr[index];
}

template<typename T>
void dArray<T>::operator= (const dArray& obj)
{
    for (size_t i = 0; i < this->nrOfElements; i++)
    {
        delete this->arr[i];
    }
    delete[] arr;

    this->initialCap = obj.initialCap;
    this->cap = obj.cap;
    this->nrOfElements = obj.nrOfElements;

    this->arr = new T * [this->cap];

    for (size_t i = 0; i < this->nrOfElements; i++)
    {
        this->arr[i] = new T(*obj.arr[i]);
    }

    this->initialize(0);
}

template<typename T>
void dArray<T>::expand()
{
    this->cap *= 2;

    T** tempArr = new T * [this->cap];

    for (size_t i = 0; i < this->nrOfElements; i++)
    {
        tempArr[i] = this->arr[i];
    }

    delete[]arr;

    this->arr = tempArr;

    this->initialize(this->nrOfElements);
}

template<typename T>
void dArray<T>::initialize(unsigned from)
{
    for (size_t i = from; i < this->cap; i++)
    {
        this->arr[i] = nullptr;
    }
}

template<typename T>
unsigned dArray<T>::maxCap()
{
    return this->cap;
}

template<typename T>
unsigned dArray<T>::size()
{
    return this->nrOfElements;
}

template<typename T>
void dArray<T>::push(const T element)
{
    if (this->nrOfElements >= this->cap)
        this->expand();

    this->arr[this->nrOfElements++] = new T(element);
}

template<typename T>
void dArray<T>::remove(const unsigned index, bool ordered)
{
    if (index >= this->nrOfElements)
        throw "OUT OF BOUNDS REMOVE.";

    if (ordered)
    {
        delete this->arr[index];

        for (size_t i = 0; i < this->nrOfElements - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }

        this->arr[--this->nrOfElements] = nullptr;
    }
    else
    {
        delete this->arr[index];

        this->arr[index] = this->arr[this->nrOfElements - 1];

        this->arr[--this->nrOfElements] = nullptr;
    }
}

#endif //TEXTRPGGAME_DARRAY_H
