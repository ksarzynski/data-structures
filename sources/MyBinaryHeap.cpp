//
// Created by kacpe on 20.06.2021.
//

#include <iostream>
#include <conio.h>
#include "../headers/MyBinaryHeap.h"

MyBinaryHeap::MyBinaryHeap() {
    this -> arraySize = 5;
    this -> array = new int[arraySize];
    for(int i = 0; i < arraySize; i++)
        array[i] = INT_MIN;
    this -> currentSize = 0;
}

MyBinaryHeap::~MyBinaryHeap() {
    delete[] array;
}

void MyBinaryHeap::insert(int data, int index) {
    if((currentSize + 1) > arraySize){
        arraySize += arraySize;
        int * temp = new int[arraySize];
        for(int i = 0; i < (arraySize / 2); i++)
            temp[i] = array[i];
        for(int i = arraySize / 2; i < arraySize; i++)
            temp[i] = INT_MIN;
        array = temp;
        delete[] temp;
    }
    int i = currentSize;
    currentSize++;
    int j = ( i - 1 ) / 2;
    while(i > 0 && array[j] < data){
        array[i] = array[j];
        i = j;
        j = ( i - 1 ) / 2;
    }
    array[i] = data;
}

void MyBinaryHeap::remove(int index) {
    if(index < 0){
        std::cout << "Wrong index, press button";
        _getch();
    }
    else if(index >= currentSize){

        std::cout << "Index out of range, press button";
        _getch();
    }
    else{
        array[index] = array[currentSize - 1];
        array[currentSize - 1] = INT_MIN;
        currentSize--;
        repair(0);
    }
}

void MyBinaryHeap::removeValue(int value) {
    if(findByValue(value) != INT_MIN)
        this -> remove(this -> findByValue(value));
}

int MyBinaryHeap::findByIndex(int index) {
    if(index < currentSize && currentSize >= 0){
        return array[index];
    }
    else{
        std::cout << "Index out of range, press button" << std::endl;
        _getch();
        return 0;
    }
}

int MyBinaryHeap::findByValue(int value) {
    int temp = INT_MIN;
    for(int i = 0; i < currentSize; i++){
        if(array[i] == value){
            temp = i;
            break;
        }
    }
    if(temp == INT_MIN){
        std::cout << "Value not found, press button";
        _getch();
        return INT_MIN;
    }
    return temp;
}

void MyBinaryHeap::createRandom(int newSize) {
    this->currentSize = 0;
    for(int i = 0; i < newSize; i++){
        this -> insert(rand() % 1000, 0);
    }
}

void MyBinaryHeap::print() {
    printHeap("", "", 0);
}

void MyBinaryHeap::printHeap(std::string sp, std::string sn, int v) {
    if(currentSize != 0){
        std::string cr, cl, cp;
        cr = cl = cp = "  ";
        cr [ 0 ] = 218; cr [ 1 ] = 196;
        cl [ 0 ] = 192; cl [ 1 ] = 196;
        cp [ 0 ] = 179;
        std::string s;
        if( v < currentSize )
        {
            s = sp;
            if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
            this -> printHeap ( s + cp, cr, 2 * v + 2 );
            s = s.substr ( 0, sp.length( ) - 2 );
            std::cout << s << sn << array[v] << std::endl;
            s = sp;
            if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
            this -> printHeap ( s + cp, cl, 2 * v + 1 );
        }
    }
}

int MyBinaryHeap::getHeight() const {
    int temp = currentSize;
    int height = 0;
    while(temp >= 1){
        temp /= 2;
        height++;
    }
    return height;
}

void MyBinaryHeap::repair(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int j = index;
    int temp = 0;
    if((left < currentSize) && (array[left] > array[index]))
        j = left;
    if((right < currentSize) && (array[right] > array[j]))
        j = right;
    if(j != index){
        temp = array[index];
        array[index] = array[j];
        array[j] = temp;
        repair(j);
    }
}

int MyBinaryHeap::getSize() {
    return this->currentSize;
}

int MyBinaryHeap::findByValueNoCout(int value) {
    int temp = INT_MIN;
    for(int i = 0; i < currentSize; i++){
        if(array[i] == value){
            temp = i;
            break;
        }
    }
    if(temp == INT_MIN){
        return INT_MIN;
    }
    return temp;
}

std::string MyBinaryHeap::getName() {
    return "MyBinaryHeap";
}
