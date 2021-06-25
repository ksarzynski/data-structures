//
// Created by kacpe on 24.06.2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include "../headers/TestRunner.h"
#include "../headers/MyArray.h"
#include "../headers/MyList.h"
#include "../headers/MyBinaryHeap.h"
#include "../headers/MyBinarySearchTree.h"


TestRunner::TestRunner() {
    run();
}

void TestRunner::run() {
    // for some reason only absolute path works atm
    std::string fileName = R"(C:\Users\kacpe\CLionProjects\data_structures\.CONFIG)";
    std::string content;
    std::ifstream file(fileName);
    int lineCounter = 0;
    int index = 0;
    /*
     * there will be 7x4=28 values read from file,
     * each data structure needs 7 to be tested
     * 1. value - is this ds to be tested
     * 2. value - size
     * 3. value - how many times insert operation is to be tested
     * 4. value - how many times removeByIndex operation is to be tested
     * 5. value - how many times removeByValue operation is to be tested
     * 6. value - how many times findByIndex operation is to be tested
     * 7. value - how many times findByValue operation is to be tested
     */
    int *fileValues = new int[28];
    while(std::getline(file, content)){
        if(content[0] != '*'){
            fileValues[index] = getInt(content);
            index ++;
            lineCounter++;
        }
    }
    std::cout << "Do u want to save results? Enter 1 if yes\n";
    std::cin >> input;
    if(input == 1){
        save = true;
        std::cout << "Enter file name\n";
        std::cin >> resultsFileName;
    }
    else
        save = false;
    test("MyArray", fileValues);
    test("MyList", fileValues);
    test("MyBinaryHeap", fileValues);
    test("MyBinarySearchTree", fileValues);
}

int TestRunner::getInt(std::string content) {
    int scale = 1;
    int value = 0;
    for(int i = content.size() - 1; i > -1; i--){
        value += (content[i] - 48) * scale;
        scale *= 10;
    }
    return value;
}

void TestRunner::test(const std::string& dataStructure, const int *values) {
    if(dataStructure == "MyArray"){
        std::cout << "Testing MyArray:\n";
        int *temp = new int[7];
        for(int i = 0; i < 7; i++)
            temp[i] = values[i];
        test(new MyArray(), temp);
    }
    else if(dataStructure == "MyList"){
        std::cout << "Testing MyList:\n";
        int *temp = new int[7];
        for(int i = 7; i < 14; i++)
            temp[i - 7] = values[i];
        test(new MyList(), temp);
    }
    else if(dataStructure == "MyBinaryHeap"){
        std::cout << "Testing MyBinaryHeap:\n";
        int *temp = new int[7];
        for(int i = 14; i < 21; i++)
            temp[i - 14] = values[i];
        test(new MyBinaryHeap(), temp);
    }
    else if(dataStructure == "MyBinarySearchTree"){
        std::cout << "Testing MyBinarySearchTree:\n";
        int *temp = new int[7];
        for(int i = 21; i < 28; i++)
            temp[i - 21] = values[i];
        test(new MyBinarySearchTree(), temp);
    }
    else{
        std::cout << "Wrong input, press button";
        _getch();
    }
}

void TestRunner::test(MyDataStructure *myDataStructure, int *values) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> indexDistribution(0, myDataStructure->getSize());
    std::uniform_int_distribution<int> valueDistribution(0, 5000);
    insertTime = 0;
    removeByIndexTime = 0;
    removeByValueTime = 0;
    findByIndexTime = 0;
    findByValueTime = 0;
    int index;
    int value;
    if(values[0] == 1){
        myDataStructure->createRandom(values[1]);
        for(int i = 0; i < values[2]; i++){
            index = indexDistribution(generator);
            value = valueDistribution(generator);
            auto start = std::chrono::high_resolution_clock::now();
            myDataStructure->insert(value, index);
            auto stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = stop - start;
            insertTime += diff.count();
            value = valueDistribution(generator);
            while(myDataStructure->findByValueNoCout(value) == INT_MIN)
                value = valueDistribution(generator);
            myDataStructure->removeValue(value);
        }
        std::cout << "Inserting " << values[2] << " elements took: " << insertTime << " ms.\n";
        for(int i = 0; i < values[3]; i++){
            index = indexDistribution(generator);
            auto start = std::chrono::high_resolution_clock::now();
            myDataStructure->remove(index);
            auto stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = stop - start;
            removeByIndexTime += diff.count();
            value = valueDistribution(generator);
            myDataStructure->insert(value, 0);
        }
        std::cout << "Removing by index " << values[3] << " elements took: " << removeByIndexTime << " ms.\n";
        for(int i = 0; i < values[4]; i++){
            value = valueDistribution(generator);
            index = indexDistribution(generator);
            myDataStructure->insert(value, index);
            auto start = std::chrono::high_resolution_clock::now();
            myDataStructure->removeValue(value);
            auto stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = stop - start;
            removeByValueTime += diff.count();
            value = valueDistribution(generator);
            myDataStructure->insert(value, 0);
        }
        std::cout << "Removing by value " << values[4] << " elements took: " << removeByValueTime << " ms.\n";
        for(int i = 0; i < values[5]; i++){
            index = indexDistribution(generator);
            auto start = std::chrono::high_resolution_clock::now();
            myDataStructure->findByIndex(index);
            auto stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = stop - start;
            findByIndexTime += diff.count();
        }
        std::cout << "Finding by index " << values[5] << " elements took: " << findByIndexTime << " ms.\n";
        for(int i = 0; i < values[6]; i++){
            value = valueDistribution(generator);
            index = indexDistribution(generator);
            myDataStructure->insert(value, index);
            auto start = std::chrono::high_resolution_clock::now();
            myDataStructure->findByValue(value);
            auto stop = std::chrono::high_resolution_clock::now();
            myDataStructure->removeValue(value);
            std::chrono::duration<double> diff = stop - start;
            findByValueTime += diff.count();
        }
        std::cout << "Finding by value " << values[6] << " elements took: " << findByValueTime << " ms.\n";
        if(save)
            saveToFile(resultsFileName, values, myDataStructure->getName());
    }
}

void TestRunner::saveToFile(const std::string& fileName, int *values, const std::string& dataStructure) {
    std::ofstream myFile;
    myFile.open(fileName + "-" + dataStructure + ".txt");
    myFile << dataStructure << ":\n";
    myFile << "Inserting\n";
    myFile << values[2] << ";" << insertTime << "\n";
    myFile << "Removing by index\n";
    myFile << values[3] << ";" << removeByIndexTime << "\n";
    myFile << "Removing by value\n";
    myFile << values[4] << ";" << removeByValueTime << "\n";
    myFile << "Finding by index\n";
    myFile << values[5] << ";" << findByIndexTime << "\n";
    myFile << "Finding by value\n";
    myFile << values[6] << ";" << findByValueTime << "\n";
    myFile.close();
}
