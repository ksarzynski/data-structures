//
// Created by kacpe on 19.06.2021.
//

#ifndef DATA_STRUCTURES_MYLIST_H
#define DATA_STRUCTURES_MYLIST_H


#include "MyListElement.h"
#include "MyDataStructure.h"

class MyList : public MyDataStructure{

public:
    MyList();
    ~MyList();
    void pushFront(int data);
    void pushBack(int data);
    void insert(int data, int index);
    void popFront();
    void popBack();
    void remove(int index);
    void removeValue(int value);
    int findByIndex(int index);
    int findByValue(int value);
    void print();
    void createRandom(int newSize);
    int getSize();
    int findByValueNoCout(int value);
    std::string getName();

private:

    int size;
    MyListElement * head;
    MyListElement * tail;
    MyListElement * findElementByIndexMLE(int index);
    MyListElement * findElementByValueMLE(int value);
    MyListElement * findElementByValueMLENoCout(int value);
};


#endif //DATA_STRUCTURES_MYLIST_H
