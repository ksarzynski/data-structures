//
// Created by kacpe on 19.06.2021.
//

#ifndef DATA_STRUCTURES_MYARRAY_H
#define DATA_STRUCTURES_MYARRAY_H


#include "MyDataStructure.h"

class MyArray : public MyDataStructure {

public:
    MyArray();
    ~MyArray();
    void insert(int data, int index);
    void remove(int index);
    void removeValue(int value);
    int findByIndex(int index);
    int findByValue(int value);
    void print();
    void createRandom(int newSize);
    int getSize();

private:
    int * dataPointer;
    int size;
    void relocateAndIncrease(int data, int index);
    void relocateAndDecrease(int index);
};


#endif //DATA_STRUCTURES_MYARRAY_H
