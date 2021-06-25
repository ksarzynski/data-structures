//
// Created by kacpe on 24.06.2021.
//

#include <iostream>
#include <conio.h>
#include "../headers/ConsoleApp.h"
#include "../headers/MyArray.h"
#include "../headers/MyList.h"
#include "../headers/MyBinaryHeap.h"
#include "../headers/MyBinarySearchTree.h"
#include "../headers/TestRunner.h"

ConsoleApp::ConsoleApp() {
    running = true;
    myDataStructure = new MyArray();
    start();
}

void ConsoleApp::start() {
    chooseTest();
}

void ConsoleApp::chooseTest() {
    int input;
    while(running){
        std::cout << "1. Manual testing\n";
        std::cout << "2. Automatic testing (configured in .CONFIG file)\n";
        std::cout << "3. Exit\n";
        std::cin >> input;
        if(input == 1){
            manualTesting();
        }
        else if(input == 2){
            automaticTesting();
        }
        else if(input == 3){
            running = false;
        }
        else{
            std::cout << "Wrong option, press button\n";
            _getch();
        }
    }
}

void ConsoleApp::manualTesting() {
    int input;
    bool manualTestingRunning = true;
    while(manualTestingRunning) {
        std::cout << "1. Testing MyArray\n";
        std::cout << "2. Testing MyList\n";
        std::cout << "3. Testing MyBinaryHeap\n";
        std::cout << "4. Testing MyBinarySearchTree\n";
        std::cout << "5. Exit\n";
        std::cin >> input;
        if(input == 1){
            myDataStructure = new MyArray();
            testingStructure();
        }
        else if(input == 2){
            myDataStructure = new MyList();
            testingStructure();
        }
        else if(input == 3){
            myDataStructure = new MyBinaryHeap();
            testingStructure();
        }
        else if(input == 4){
            myDataStructure = new MyBinarySearchTree();
            testingStructure();
        }
        else if(input == 5){
            manualTestingRunning = false;
        }
        else{
            std::cout << "Wrong option, press button\n";
            _getch();
        }
    }
}

void ConsoleApp::automaticTesting() {
    new TestRunner();
}

void ConsoleApp::testingStructure() {
    int input;
    bool testingStructureRunning = true;
    while(testingStructureRunning) {
        myDataStructure->print();
        std::cout << "1. Create structure with random data of given size\n";
        std::cout << "2. Insert element\n";
        std::cout << "3. Remove element by index\n";
        std::cout << "4. Remove element by value\n";
        std::cout << "5. Find element by index\n";
        std::cout << "6. Find element by value\n";
        std::cout << "7. Exit\n";
        std::cin >> input;
        if(input == 1){
            int size;
            std::cout << "Enter size\n";
            std::cin >> size;
            myDataStructure->createRandom(size);
        }
        else if(input == 2){
            int value;
            std::cout << "Enter value\n";
            std::cin >> value;
            int index;
            std::cout << "Enter index\n";
            std::cin >> index;
            myDataStructure->insert(value, index);
        }
        else if(input == 3){
            int index;
            std::cout << "\nEnter index\n";
            std::cin >> index;
            myDataStructure->remove(index);
        }
        else if(input == 4){
            int value;
            std::cout << "\nEnter value\n";
            std::cin >> value;
            myDataStructure->removeValue(value);
        }
        else if(input == 5){
            int index;
            std::cout << "\nEnter index\n";
            std::cin >> index;
            myDataStructure->findByIndex(index);
        }
        else if(input == 6){
            int value;
            std::cout << "\nEnter value\n";
            std::cin >> value;
            myDataStructure->findByValue(value);
        }
        else if(input == 7){
            testingStructureRunning = false;
        }
        else{
            std::cout << "Wrong option, press button\n";
            _getch();
        }
    }
}
