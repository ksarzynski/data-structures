//
// Created by kacpe on 20.06.2021.
//

#ifndef DATA_STRUCTURES_MYBSTNODE_H
#define DATA_STRUCTURES_MYBSTNODE_H


class MyBstNode {

public:
    MyBstNode(int key);
    ~MyBstNode();
    int getKey();

private:
    friend class MyBinarySearchTree;
    int key;
    MyBstNode * left;
    MyBstNode * right;
    MyBstNode * parent;
};


#endif //DATA_STRUCTURES_MYBSTNODE_H
