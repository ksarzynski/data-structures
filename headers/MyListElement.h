//
// Created by kacpe on 19.06.2021.
//

#ifndef DATA_STRUCTURES_MYLISTELEMENT_H
#define DATA_STRUCTURES_MYLISTELEMENT_H


class MyListElement {

public:
    MyListElement(int data, MyListElement * prev, MyListElement * next);

private:
    int data;
    MyListElement * prev;
    MyListElement * next;
    friend class MyList;
};


#endif //DATA_STRUCTURES_MYLISTELEMENT_H
