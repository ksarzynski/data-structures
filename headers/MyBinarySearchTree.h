//
// Created by kacpe on 20.06.2021.
//

#ifndef DATA_STRUCTURES_MYBINARYSEARCHTREE_H
#define DATA_STRUCTURES_MYBINARYSEARCHTREE_H


#include "MyDataStructure.h"
#include "MyBstNode.h"
#include "PrintHelper.h"

class MyBinarySearchTree : public MyDataStructure{

public:

    MyBinarySearchTree();
    ~MyBinarySearchTree();
    void insert(int data, int index);
    void remove(int index);
    void removeValue(int value);
    int findByIndex(int index);
    int findByValue(int value);
    void createRandom(int size);
    void print();
    void preorder(MyBstNode * ptr);
    void inorder(MyBstNode * ptr);
    void postorder(MyBstNode * ptr);
    int getSize();

private:
    MyBstNode * root;
    int size;

    void removeValue(MyBstNode * node, int value);
    MyBstNode * findByValueMBN(int value);
    MyBstNode * findSuccessor(MyBstNode * node);
    MyBstNode * findPredecessor(MyBstNode * node);
    void dsw(MyBstNode * node);
    void rotateRight(MyBstNode * node);
    void rotateLeft(MyBstNode * node);
    void print(MyBstNode * node, PrintHelper * prev, bool isLeft);
};


#endif //DATA_STRUCTURES_MYBINARYSEARCHTREE_H
