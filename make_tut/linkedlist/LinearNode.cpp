#ifndef LINEARNODE_cpp
#define LINEARNODE_cpp
#include<iostream>
#include"LinearNode.h"

using namespace std;

//Constructor for LinearNode, sets next and element to initialized states
LinearNode::LinearNode()
{
    next = NULL;
    element = 0;
}//ends LinearNode default constructor

//Constructor for LinearNode takes an element as argument.
LinearNode::LinearNode(int el)
{
    next = NULL;
    previous = NULL;
    element = 0;
}//ends LinearNode constructor

//returns the next element in the structure
LinearNode* LinearNode::getNext()
{
    return next;
}//ends getNext function

//returns previous element in structure
LinearNode* LinearNode::getPrevious()
{
    return previous;
}//ends getPrevious function

//sets the next variable for the node
void LinearNode::setNext(LinearNode* node)
{
    next = node;
}//ends the setNext function

//sets previous for the node
void LinearNode::setPrevious(LinearNode* node)
{
    previous = node;
}//ends the setPrevious function

//returns element of the node
int LinearNode::getElement()
{
    return element;
}//ends the getelement function

//sets the element of the node
void LinearNode::setElement(int el)
{
    element = el;
}//ends the setElement function

#endif
