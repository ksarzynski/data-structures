//
// Created by kacpe on 20.06.2021.
//

#include <conio.h>
#include <iostream>
#include "../headers/MyBinarySearchTree.h"

MyBinarySearchTree::MyBinarySearchTree() {
    root = nullptr;
    size = 0;
}

MyBinarySearchTree::~MyBinarySearchTree() {
    delete root;
}

void MyBinarySearchTree::insert(int data, int index) {
    size++;
    auto * insertNode = new MyBstNode(data);
    if(root == nullptr){
        root = insertNode;
        return;
    }
    MyBstNode * parent = nullptr;
    auto x = root;
    while(x != nullptr){
        parent = x;
        if(data  < x -> getKey())
            x = x -> left;
        else
            x = x -> right;
    }
    insertNode -> parent = parent;
    if(data < parent -> getKey())
        parent -> left = insertNode;
    else
        parent -> right = insertNode;
    dsw(root);
}

void MyBinarySearchTree::remove(int index) {
    std::cout << "u cant do this its bst, press a button";
    _getch();
}

void MyBinarySearchTree::removeValue(int value) {
    removeValue(root, value);
    dsw(root);
}

int MyBinarySearchTree::findByIndex(int index) {
    std::cout << "u cant do this its bst, press a button";
    _getch();
    return INT_MIN;
}

int MyBinarySearchTree::findByValue(int value) {
    return findByValueMBN(value)->key;
}

void MyBinarySearchTree::createRandom(int newSize) {
    this->size = 0;
    this->root = nullptr;
    srand(time(NULL));
    for(int i = 0; i < newSize; i++){
        this -> insert(rand() % 1000, 0);
    }
}

void MyBinarySearchTree::print() {
    std::cout << std::endl << "size: " << size << std::endl;
    print(root, nullptr, false);
}

void MyBinarySearchTree::preorder(MyBstNode *ptr) {
    if(ptr == nullptr)
        return;
    std::cout << ptr -> getKey() << " ";
    preorder(ptr -> left);
    preorder(ptr -> right);
}

void MyBinarySearchTree::inorder(MyBstNode *ptr) {
    if(ptr == nullptr)
        return;
    preorder(ptr -> left);
    std::cout << ptr -> getKey() << " ";
    preorder(ptr -> right);
}

void MyBinarySearchTree::postorder(MyBstNode *ptr) {
    if(ptr == nullptr)
        return;
    preorder(ptr -> left);
    preorder(ptr -> right);
    std::cout << ptr -> getKey() << " ";
}

void MyBinarySearchTree::removeValue(MyBstNode *node, int value) {
    auto toDelete = findByValueMBN(value);
    if(toDelete){
        MyBstNode * y;
        MyBstNode * x;
        if(toDelete -> parent == nullptr && toDelete -> left == nullptr && toDelete -> right == nullptr)
            this -> root = nullptr;
        if((toDelete -> left == nullptr) || (toDelete -> right == nullptr))
            y = toDelete;
        else
            y = findSuccessor(toDelete);
        if(y -> left != nullptr)
            x = y -> left;
        else
            x = y -> right;
        if(x != nullptr)
            x -> parent = y -> parent;
        if(y -> parent == nullptr)
            this -> root = x;
        else{
            if(y == (y -> parent -> left))
                y -> parent -> left = x;
            else
                y -> parent -> right = x;
        }
        if(y != toDelete){
            toDelete -> key = y -> key;
        }
        size--;
    }
    dsw(root);
}

MyBstNode *MyBinarySearchTree::findByValueMBN(int value) {
    MyBstNode * node = root;
    if(node == nullptr){
        std::cout << "Bst is empty, press a button";
        _getch();
        return nullptr;
    }
    if(root -> getKey() == value)
        return root;
    while((node != nullptr) && (node -> getKey() != value)){
        if(value < node -> getKey() && node -> left != nullptr)
            node = node -> left;
        else if(value > node -> getKey() && node -> right != nullptr)
            node = node -> right;
        else{
            std::cout << "Value not found, press a button";
            _getch();
            return nullptr;
        }
    }
    return node;
}

MyBstNode *MyBinarySearchTree::findSuccessor(MyBstNode *node) {
    MyBstNode * temp;
    if(node -> right){
        temp = node -> right;
        while(temp -> left){
            temp = temp -> left;
        }
        return temp;
    }
    else if(!(node -> right)){
        if(node -> parent){
            temp = node -> parent;
            while(temp -> getKey() < node -> getKey() && temp -> parent){
                temp = temp -> parent;
            }
            return temp;
        }
    }
    return findPredecessor(node);
}

MyBstNode *MyBinarySearchTree::findPredecessor(MyBstNode *node) {
    MyBstNode * temp;
    if(node -> left){
        temp = node -> left;
        while(temp -> right){
            temp = temp -> right;
        }
        return temp;
    }
    else if(!(node -> left)){
        if(node -> parent){
            temp = node -> parent;
            while(temp -> getKey() > node -> getKey() && temp -> parent){
                temp = temp -> parent;
            }
            return temp;
        }
    }
    return nullptr;
}

void MyBinarySearchTree::dsw(MyBstNode *node) {
    MyBstNode * ptr = root;
    int s = size;
    if(root){
        MyBstNode * temp = node;
        while(temp){
            if(temp -> left){
                rotateRight(temp);
                temp = temp -> parent;
            }
            else
                temp = temp -> right;
        }
        int m = pow(2, floor(log2(this -> size + 1))) - 1;
        ptr = root;
        for(int i = 0; i < (size - m); i++){
            rotateLeft(ptr);
            ptr = ptr -> parent -> right;
        }
        s -= (size - m);
        while(s > 1){
            s /= 2;
            ptr = root;
            for(int i = 0; i < s; i++){
                rotateLeft(ptr);
                ptr = ptr -> parent -> right;
            }
        }
    }
}

void MyBinarySearchTree::rotateRight(MyBstNode *node) {
    MyBstNode * temp = node -> left;
    MyBstNode * par = node -> parent;
    if(temp){
        node -> left = temp -> right;
        if(node -> left)
            node -> left -> parent = node;
        temp -> right = node;
        temp -> parent = par;
        node -> parent = temp;
        if(par){
            if(par -> left == node)
                par -> left = temp;

            else
                par -> right = temp;
        }
        else
            root = temp;
    }
}

void MyBinarySearchTree::rotateLeft(MyBstNode *node) {
    MyBstNode * temp = node -> right;
    MyBstNode * par = node -> parent;
    if(temp){
        node -> right = temp -> left;
        if(node -> right)
            node -> right -> parent = node;
        temp -> left = node;
        temp -> parent = par;
        node -> parent = temp;
        if(par){
            if(par -> left == node)
                par -> left = temp;
            else
                par -> right = temp;
        }
        else
            root = temp;
    }
}

void MyBinarySearchTree::print(MyBstNode *node, PrintHelper *prev, bool isLeft) {
    if(node == nullptr)
        return;
    std::string prevStr = "    ";
    auto helper = new PrintHelper(prev, prevStr);
    print(node -> right, helper, true);
    if(!prev)
        helper -> str = "---";
    else if(isLeft){
        helper -> str = ".---";
        prevStr = "   |";
    }
    else{
        helper -> str = "`---";
        prev -> str = prevStr;
    }
    helper -> printBranch(helper);
    std::cout << node -> key << std::endl;
    if(prev)
        prev -> str = prevStr;
    helper -> str = "   |";
    print(node -> left, helper, false);
}

int MyBinarySearchTree::getSize() {
    return this->size;
}
