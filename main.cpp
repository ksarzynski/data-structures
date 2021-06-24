#include <iostream>
#include "headers/MyList.h"
#include "headers/MyArray.h"
#include "headers/MyBinaryHeap.h"
#include "headers/MyBinarySearchTree.h"

// todo ogarniecie createRandom
// todo ogarniecie pamieci
// todo aplikacja konsolowa
// todo testowanie z pliku

int main() {

    auto myDataStructure = new MyBinarySearchTree();
    myDataStructure->createRandom(10);
    myDataStructure->print();

}
