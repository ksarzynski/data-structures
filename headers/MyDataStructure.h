//
// Created by kacpe on 19.06.2021.
//

#ifndef DATA_STRUCTURES_MYDATASTRUCTURE_H
#define DATA_STRUCTURES_MYDATASTRUCTURE_H

#include <string>

class MyDataStructure {

public:

    virtual void insert(int data, int index) = 0;
    virtual void remove(int index) = 0;
    virtual void removeValue(int value) = 0;
    virtual int findByIndex(int index) = 0;
    virtual int findByValue(int value) = 0;
    virtual void print() = 0;
    virtual void createRandom(int newSize) = 0;
    virtual int getSize() = 0;
    virtual int findByValueNoCout(int value) = 0;
    virtual std::string getName() = 0;
};


#endif //DATA_STRUCTURES_MYDATASTRUCTURE_H
