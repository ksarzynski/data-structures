//
// Created by kacpe on 20.06.2021.
//

#ifndef DATA_STRUCTURES_MYBINARYHEAP_H
#define DATA_STRUCTURES_MYBINARYHEAP_H


#include <xstring>
#include "MyDataStructure.h"

class MyBinaryHeap : public MyDataStructure{

public:
    MyBinaryHeap();
    ~MyBinaryHeap();
    void insert(int data, int index);
    void remove(int index);
    void removeValue(int value);
    int findByIndex(int index);
    int findByValue(int value);
    void createRandom(int newSize);
    void print();
    int getSize();
    int findByValueNoCout(int value);

private:
    int * array;
    int currentSize;
    int arraySize;

    int getHeight() const;
    void repair(int index);
    void printHeap(std::string sp, std::string sn, int v);
};


#endif //DATA_STRUCTURES_MYBINARYHEAP_H
