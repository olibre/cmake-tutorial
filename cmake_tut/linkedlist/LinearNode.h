#ifndef LINEARNODE_H
#define LINEARNODE_H
#include<iostream>

using namespace std;

class LinearNode
{
    public:
        //Constructor for the LinearNode class that takes no arguments 
        LinearNode();
        //Constructor for the LinearNode class that takes the element as an argument
        LinearNode(int el);
        //returns the next node in the set.
        LinearNode* getNext();
        //returns the previous node in the set
        LinearNode* getPrevious();
        //sets the next element in the set
        void setNext(LinearNode* node);
        //sets the previous element in the set
        void setPrevious(LinearNode* node);
        //sets the element of the node
        void setElement(int el);
        //gets the element of the node
        int getElement();

    private: 
        LinearNode* next;
        LinearNode* previous;
        int element;        
};//ends the LinearNode class

#endif
