//
// Created by kacpe on 20.06.2021.
//

#include <iostream>
#include <utility>
#include "../headers/PrintHelper.h"

PrintHelper::PrintHelper(PrintHelper * prev, std::string str){
    this -> prev = prev;
    this -> str = std::move(str);
}

void PrintHelper::printBranch(PrintHelper * ptr){
    if(ptr == nullptr)
        return;
    printBranch(ptr -> prev);
    std::cout << ptr -> str;
}

PrintHelper::~PrintHelper() {
    delete prev;
}
