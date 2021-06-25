//
// Created by kacpe on 24.06.2021.
//

#ifndef DATA_STRUCTURES_TESTRUNNER_H
#define DATA_STRUCTURES_TESTRUNNER_H

#include <string>
#include <conio.h>
#include "MyDataStructure.h"

/*
 * Example .CONFIG file:
 *
    *MyArray - doesn't rly do anything its for user to know what structure he is testing
    1 - 1 if u want to test it, 0 if u don't
    1000 - size
    *insert - same as *MyArray, it only tells user what operation is test performing
    1000 - how many times do u want to repeat operation above
    *removeByIndex
    1000
    *removeByValue
    1000
    *findByIndex
    1000
    *findByValue
    1000
    *MyList
    1
    1000
    *insert
    1000
    *removeByIndex
    1000
    *removeByValue
    1000
    *findByIndex
    1000
    *findByValue
    1000
    *MyBinaryHeap
    1
    500
    *insert
    200
    *removeByIndex
    0
    *removeByValue
    200
    *findByIndex
    0
    *findByValue
    0
    *MyBinarySearchTree
    0
    0
    *insert
    0
    *removeByIndex
    0
    *removeByValue
    0
    *findByIndex
    0
    *findByValue
    0
 */

class TestRunner {

public:
    TestRunner();

private:
    void run();
    int getInt(std::string content);
    void test(const std::string& dataStructure, int *values);
    void test(MyDataStructure *myDataStructure, int *values);
};


#endif //DATA_STRUCTURES_TESTRUNNER_H
