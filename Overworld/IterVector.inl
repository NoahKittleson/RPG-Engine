//
//  IterList.cpp
//  Test Jet Radio
//
//  Created by Noah Kittleson on 12/30/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

//#include "IterVector.hpp"
//#include <exception>

    
template <typename T>
IterVector<T>::IterVector (bool Loop)
{
    this->looping = Loop;
}

template <typename T>
IterVector<T>& IterVector<T>::operator++()
{
    ++index;
    if (looping && index >= this->size()) {  //if size is 7, maximum index is 6
        index = 0;
    }
    return *this;
}

template <typename T>
IterVector<T>& IterVector<T>::operator--()
{
    if (looping && index <= 0) {
        index = this->size();
    }
    --index;
    return *this;
}

template <typename T>
void IterVector<T>::setLooping(bool Loop)
{
    looping = Loop;
}

template <typename T>
void IterVector<T>::forAll(void (*funcPtr)(T)) {
    for (int iii = 0; iii < this->size(); iii++) {
        funcPtr(this[iii]);
    }
}

template <typename T>
void IterVector<T>::reset()
{
    index = 0;
}


template <typename T>
T& IterVector<T>::get()
{
    if(this->empty()) {
        throw "nothing to get";
    }
    return (*this)[index];
}

template <typename T>
const T& IterVector<T>::get() const
{
    if (this->empty()) {
        throw "nothing to get";
    }
    return (*this)[index];
}

template <typename T>
bool IterVector<T>::atEnd()
{
    if (!looping && index >= this->size()-1) {
        return true;
    }
    return false;
}




