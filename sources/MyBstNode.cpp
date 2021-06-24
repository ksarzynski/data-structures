//
// Created by kacpe on 20.06.2021.
//

#include "../headers/MyBstNode.h"

MyBstNode::MyBstNode(int key) {
    this -> key = key;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

int MyBstNode::getKey() {
    return key;
}
