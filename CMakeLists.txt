cmake_minimum_required(VERSION 3.19)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures main.cpp sources/MyList.cpp headers/MyList.h sources/MyArray.cpp headers/MyArray.h sources/MyListElement.cpp headers/MyListElement.h headers/MyDataStructure.h sources/MyBinaryHeap.cpp headers/MyBinaryHeap.h sources/MyBstNode.cpp headers/MyBstNode.h sources/MyBinarySearchTree.cpp headers/MyBinarySearchTree.h sources/PrintHelper.cpp headers/PrintHelper.h sources/ConsoleApp.cpp headers/ConsoleApp.h)