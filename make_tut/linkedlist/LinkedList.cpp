#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include<iostream>
#include"LinearNode.h"
#include"LinkedList.h"

using namespace std;

//linkedlist constructor for an empty linked list
LinkedList::LinkedList()
{
    count = 0;
    contents = NULL;
}//ends the constructor

//adds an element to the front of the linked list
void LinkedList::add(int element)
{
    int found = 0, current = 0;

    while( (found == 0) && (current !=count) )
    {
        if (contents->getElement() == element)
            found = 1;
        else    
        {
            contents = contents->getNext();
            current++;
        }//ends the else statement
    }//ends the while loop

    if (found == 0)
    {
        LinearNode* node = new LinearNode(element);
        node->setNext(contents);
        contents->setPrevious(node);
        count++;
    }//ends the found == 0 if statment
}//ends the add function

//this function removes one element from the linked list.
int LinkedList::remove(int element)
{
    int result = 0;
    return result;
}//ends the remove function

#endif
