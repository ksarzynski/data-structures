//
// Created by kacpe on 19.06.2021.
//

#include "../headers/MyListElement.h"


MyListElement::MyListElement(int data, MyListElement * prev, MyListElement * next){
    this -> data = data;
    this -> prev = prev;
    this -> next = next;
}

MyListElement::~MyListElement() {
    ;
}
