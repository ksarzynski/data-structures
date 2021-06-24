//
// Created by kacpe on 19.06.2021.
//

#include <iostream>
#include <conio.h>
#include "../headers/MyList.h"

MyList::MyList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

MyList::~MyList() {
    delete head;
    delete tail;
    size = 0;
}

void MyList::pushFront(int data) {
    if(head == nullptr && tail == nullptr){
        head = new MyListElement(data, nullptr, nullptr);
        tail = head;
        size = 1;
    }
    else{
        auto * element = new MyListElement(data, nullptr, head);
        head->prev = element;
        head = element;
        size++;
    }
}

void MyList::pushBack(int data) {
    if(head == nullptr && tail == nullptr){
        tail = new MyListElement(data, nullptr, nullptr);
        head = tail;
        size = 1;
    }
    else{
        auto element = new MyListElement(data, tail, nullptr);
        tail->next = element;
        tail = element;
        size++;
    }
}

void MyList::insert(int data, int index) {
    if(index == 0)
        this->pushFront(data);
    else if(index == size)
        this->pushBack(data);
    else{
        auto element = findElementByIndexMLE(index);
        if(element){
            auto newElement = new MyListElement(data, element->prev, element);
            element->prev->next = newElement;
            element->prev = newElement;
            size++;
        }
    }
}

void MyList::popFront() {
    if(head && tail){
        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            MyListElement * temp = head;
            head->next->prev = nullptr;
            head = head->next;
            delete temp;
        }
        size--;
    }
    else{
        std::cout << "Missing head or tail, press button";
        _getch();
        return;
    }
}

void MyList::popBack() {
    if(head && tail){
        if(head == tail){
            delete head;
            delete tail;
        }
        else{
            auto temp = tail;
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete temp;
        }
        size--;
    }
    else{
        std::cout << "Missing head or tail, press button";
        _getch();
        return;
    }
}

void MyList::remove(int index) {
    if(index < 0){
        std::cout << "Wrong index, press button";
        _getch();
        return;
    }
    else if(index == 0)
        popFront();
    else if(index == (size - 1))
        popBack();
    else if(index >= size){
        std::cout << "Index out of range, press button";
        _getch();
        return;
    }
    else{
        if(head && tail){
            if(index < (size / 2)){
                MyListElement * temp = head;
                for(int i = 0; i < index; i++){
                    if(temp->next)
                        temp = temp->next;
                    else{
                        std::cout << "Missing element of list, press button";
                        _getch();
                        return;
                    }
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
                size--;
            }
            else{
                MyListElement * temp = tail;
                for(int i = 0; i < (size - index - 1); i++){
                    if(temp->prev)
                        temp = temp->prev;
                    else{

                        std::cout << "Missing element of list, press button";
                        _getch();
                        return;
                    }
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
                size--;
            }
        }
        else{
            std::cout << "Missing head or tail, press button";
            _getch();
            return;
        }
    }
}

void MyList::removeValue(int value) {
    if(findByValue(value) != INT_MIN){
        if(findByValue(value) == 0)
            this->popFront();
        else if(findByValue(value) == (this->getSize() - 1))
            this->popBack();
        else{
            auto elementToDelete = this->findElementByValueMLE(+value);
            auto temp = elementToDelete->prev;
            elementToDelete->prev->next = elementToDelete->next;
            elementToDelete->next->prev = temp;
            delete elementToDelete;
            this->size--;
        }
    }
    else{
        std::cout << "Value not found, press button";
        _getch();
    }
}

int MyList::findByIndex(int index) {
    return findElementByIndexMLE(index)->data;
}

int MyList::findByValue(int value) {
    return findElementByValueMLE(value)->data;
}

void MyList::print() {
    std::cout << std::endl;
    std::cout << "size: " << size;
    std::cout << std::endl;
    auto temp = head;
    while(temp){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl << std::endl;
}

void MyList::createRandom(int newSize) {
    srand(time(nullptr));
    if(!head){
        for(int i = 0; i < newSize; i++){
            this->pushFront(rand() % 1000);
        }
    }
    else{
        std::cout << "List already exists, press button";
        _getch();
    }
}

int MyList::getSize() {
    return this->size;
}

MyListElement *MyList::findElementByIndexMLE(int index) {
    if(index < 0){
        std::cout << "Wrong index, press button";
        _getch();
        return nullptr;
    }
    else if(index >= size){
        std::cout << "Index out of range, press button";
        _getch();
        return nullptr;
    }
    else{
        if(head && tail){
            if(index < (size / 2)){
                auto temp = head;
                for(int i = 0; i < index; i++){
                    if(temp->next)
                        temp = temp->next;
                    else{
                        std::cout << "Missing element of list, press button";
                        _getch();
                        return nullptr;
                    }
                }
                return temp;
            }
            else{
                auto temp = tail;
                for(int i = 0; i < (size - index - 1); i++){
                    if(temp->prev)
                        temp = temp->prev;
                    else{
                        std::cout << "Missing element of list, press button";
                        _getch();
                        return nullptr;
                    }
                }
                return temp;
            }
        }
        else{
            std::cout << "Missing head or tail, press button";
            _getch();
            return nullptr;
        }
    }
}

MyListElement *MyList::findElementByValueMLE(int value) {
    int tempIndex = 0;
    if(head && tail){
        auto temp = head;
        if(temp->data == value)
            return temp;
        while(temp->next){
            tempIndex++;
            if(temp->next->data == value)
                return temp->next;
            temp = temp->next;
        }
        std::cout << "Value not found, press button";
        _getch();
        return nullptr;
    }
    else{
        std::cout << "Missing head or tail, press button";
        _getch();
        return nullptr;
    }
}
