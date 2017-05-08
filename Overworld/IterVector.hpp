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

//itervector is an ordered container that has only one available element at a time.  Cycle through the list with
// ++ or --, use .get() to grab current element.


template <typename T>
class IterVector : public std::vector<T>
{
public:
    IterVector (bool looping = true);
    IterVector& operator++();
    IterVector& operator--();
    
    IterVector operator++(int) = delete;
    IterVector operator--(int) = delete;
    
    T& get();
    const T& get() const;
    int getIndex() const;
    bool atEnd();
    
    void setLooping(bool);
    void forAll(void (*funcPtr)(T));
    void reset();                           //sets index to 0
    void removeCurrent();
    
private:
    int index{0};
    bool looping;
};

#include "IterVector.inl"
