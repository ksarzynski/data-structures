//
// Created by kacpe on 19.06.2021.
//

#include <iostream>
#include <conio.h>
#include "../headers/MyArray.h"

MyArray::MyArray() {
    this -> size = 0;
    this -> dataPointer = new int[size];
}

MyArray::~MyArray() {
    delete[] dataPointer;
}

void MyArray::insert(int data, int index) {
    if(size == 0 && index == 0){
        this -> size = 1;
        this -> dataPointer = new int[size];
        this -> dataPointer[0] = data;
        return;
    }
    else if(index < 0){
        std::cout << "Wrong index, press button";
        _getch();
        return;
    }
    else if(index > size) {
        std::cout << "Index out of range, press button";
        _getch();
        return;
    }
    else
        this -> relocateAndIncrease(data, index);
}

void MyArray::remove(int index) {
    if(index < 0){
        std::cout << "Wrong index, press button";
        _getch();
        return;
    }
    else if(index >= size){
        std::cout << "Index out of range, press button";
        _getch();
        return;
    }
    else
        this -> relocateAndDecrease(index);
}

void MyArray::removeValue(int value) {
    if(findByValue(value) != INT_MIN)
        remove(findByValue(value));
}

int MyArray::findByIndex(int index) {
    if(index < size && size >= 0){
        return dataPointer[index];
    }
    else{
        std::cout << "Index out of range, press button" << std::endl;
        _getch();
        return 0;
    }
}

int MyArray::findByValue(int value) {
    if(size > 0){
        for(int i = 0; i < size ; i++){
            if(value == this -> dataPointer[i]){
                return i;
            }
        }
        std::cout << "Value not found, press button";
        _getch();
        return 0;
    }
    else{
        std::cout << "Array is empty, press button";
        _getch();
        return 0;
    }
}

void MyArray::print() {
    std::cout << "size: " << this -> size << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << this -> dataPointer[i] << " ";
    }
    std::cout << std::endl;
}

void MyArray::createRandom(int newSize) {
    srand(time(NULL));
    if(this -> size == 0){
        for(int i = 0; i < newSize; i++){
            this -> insert(rand() % 1000, 0);
        }
    }
    else{
        std::cout << "Array already exists, press button";
        _getch();
    }
}

int MyArray::getSize() {
    return this -> size;
}

void MyArray::relocateAndIncrease(int data, int index) {
    size++;
    int * temp = dataPointer;
    dataPointer = new int[size];
    int helper = 0;
    for(int i = 0; i < size; i++){
        if(i == index){
            dataPointer[i] = data;
            helper = 1;
            continue;
        }
        dataPointer[i] = temp[i - helper];
    }
    delete[] temp;
}

void MyArray::relocateAndDecrease(int index) {
    size--;
    int * temp = dataPointer;
    dataPointer = new int[size];
    int helper = 0;
    for(int i = 0; i < size; i++){
        if(i == index){
            helper = 1;
        }
        dataPointer[i] = temp[i + helper];
    }
    delete[] temp;
}
