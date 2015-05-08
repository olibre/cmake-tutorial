#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
#include"LinearNode.h"

using namespace std;

class LinkedList
{
    public:
        LinkedList();
        void add(int element);
        int remove (int element);

    private:
        int count;
        LinearNode *contents;
};//ends the class linked list

#endif

