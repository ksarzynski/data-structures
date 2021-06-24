//
// Created by kacpe on 24.06.2021.
//

#ifndef DATA_STRUCTURES_CONSOLEAPP_H
#define DATA_STRUCTURES_CONSOLEAPP_H


#include "MyDataStructure.h"

class ConsoleApp {

public:
    ConsoleApp();
    ~ConsoleApp();

private:
    bool running;
    MyDataStructure *myDataStructure;
    void start();
    void chooseTest();
    void manualTesting();
    void automaticTesting();
    void testingStructure();
};


#endif //DATA_STRUCTURES_CONSOLEAPP_H
