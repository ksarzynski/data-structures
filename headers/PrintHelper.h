//
// Created by kacpe on 20.06.2021.
//

#ifndef DATA_STRUCTURES_PRINTHELPER_H
#define DATA_STRUCTURES_PRINTHELPER_H


#include <xstring>

class PrintHelper {

public:
    PrintHelper(PrintHelper * prev, std::string str);
    ~PrintHelper();
    void printBranch(PrintHelper * ptr);

private:
    friend class MyBinarySearchTree;
    PrintHelper * prev;
    std::string str;
};


#endif //DATA_STRUCTURES_PRINTHELPER_H
