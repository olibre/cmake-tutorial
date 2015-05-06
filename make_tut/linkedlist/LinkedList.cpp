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
        if (contents.getElement() == element)
            found = 1;
        else    
        {
            contents = contents.getNext();
            current++;
        }//ends the else statement
    }//ends the while loop

    if (found == 0)
    {
        LinearNode node = new LinearNode(element);
        node.setNext(contents);
        contents.setPrevious(node);
        count++;
    }//ends the found == 0 if statment
}//ends the add function

//this function removes one element from the linked list.
int LinearNode::remove(int element)
{
    int found = 0;

    if (count == 0)
        cout << "The list is empty" << endl;
    else 
    {
        if (contents.getElement() == element)
        {
            result = contents.getElement();
            contents = contents.getNext();
        }//ends the contents.getElement() == element
        else 
        {
            previous = contents;
            current = contents.getNext();
            for (int index = 0; ( (index < count) && (found == 0) )index++)
                if (current.getElement() = element)
                    found = 1;
                else
                {
                    previous = current;
                    current = current.getNext();
                }//ends the else statement 

            if (found == 0)
                cout << "The element is not in the list" << endl;
            else
            {
                result = current.getElement();
                previous.setNext(current.getNext());
            }//ends else statement  

        }//ends the else stamtement

        count--;
    }//ends the else statement of count == 0
    return result;
}//ends the remove function

#endif
