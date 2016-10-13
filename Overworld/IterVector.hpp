//
//  IterList.h
//  Test Jet Radio
//
//  Created by Noah Kittleson on 12/30/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include <vector>
#include <exception>

template <typename T>
class IterVector : public std::vector<T>
{
public:
    IterVector (bool = false);
    IterVector& operator++();
    IterVector& operator--();
    
    IterVector operator++(int) = delete;
    IterVector operator--(int) = delete;
    
    T& get();
    const T& get() const;
    bool atEnd();
    
    void setLooping(bool);
    void forAll(void (*funcPtr)(T));
    void reset();
    void removeCurrent();
    
private:
    int index{0};
    bool looping;
};

#include "IterVector.inl"
