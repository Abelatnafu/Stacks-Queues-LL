//
//  Stack & Queue.h
//  Lab 04
//
//  Created by Abel Atnafu on 7/25/20.
//  Copyright © 2020 Abel Atnafu. All rights reserved.
//

#ifndef Stack___Queue_h
#define Stack___Queue_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

class Stack : protected LinkedList{

public:
    //Constructor
    Stack();

    /*checks if empty
    pre :
    post:
    return:bool empty or not
    */
    bool isEmpty();
    /*
    push function
    pre : node pointer
    post:adds to the stack
    return:
       */
    void pushDollar(LinkedNode* norf);
    /*
    display starting from a given point
    pre : node pointer
    post:displays starting from the pointer
    return:
    */
    void displayStarting(LinkedNode *start);
    /*
     display the whole thing
     pre :
     post:displays everything
     return:
        */
    void  display();
    /*
     Pop function
     pre :
     post:pops the top of the stack
     return:node pointer
        */
    LinkedNode*  pop();
    /*
     Empties everything
     pre :
     post:empties the whole stack
     return:
        */
    void destroyEverything();
    /*
     gets the amount of members
     pre :
     post:count
     return:int
        */
    int getAmount();
    /*
     Peek function finds the top of the stack
     pre :
     post:peeks the top of the stack
     return:node pointer
        */
    LinkedNode*  peek();
     /*
        display the a single node
        pre :node pointer
        post:displays everything
        return:
           */
    void displayOne(LinkedNode *one);

};

class Queue : private LinkedList{

public:
    //constructor
    Queue();

    /*checks if empty
    pre :
    post:
    return:bool empty or not
    */
    bool isEmpty();
    /*
     Enqueue function
    pre :node ptr
    post:adds the ptr to the queue
    return:
    */
    void enqueue (LinkedNode* norf);
    /*
     Dequeue function
    pre :
    post:takes out the first entry
    return:node ptr
    */
    LinkedNode* dequeue();
    /*
    display starting from a given point
    pre : node pointer
    post:displays starting from the pointer
    return:
       */
    void displayStarting(LinkedNode *start);
    /*
    display the whole thing
    pre :
    post:displays everything
    return:
       */
    void  display();
    /*
    gets the amount of members
    pre :
    post:count
    return:int
       */
    int getAmount();
    /*
    Empties everything
    pre :
    post:empties the whole queue
    return:
       */
    void destroyEverything();

    /*
    Peeks from the front
    pre :
    post:return the front
    return:node pointer
       */
    LinkedNode*  peekFront();

    /*
    Peeks from the rear
    pre :
    post:return the rear
    return:node pointer
       */
    LinkedNode*  peekRear();
    /*
    display the a single node
    pre :node pointer
    post:displays everything
    return:
       */
    void displayOne(LinkedNode *one);



};


#endif /* Stack___Queue_h */

Stack :: Stack()
{
    //set eveything empty
    setCount(0);
    setHead(NULL);
    setTail(NULL);
}

void Stack :: pushDollar(LinkedNode* norf) 
{

    LinkedNode *temp = new LinkedNode;
    temp->data = norf->data ;
    temp->next = NULL;

    //empty stack
    if(getHead() == NULL)
    {
        setHead(temp);
        setTail(temp);
    }
    //if not empty
    else
    {
        temp =getHead();
        setHead(norf);
        norf->next= temp;
    }
    //add one to count
    setCount(getCountorCountList()+1);
}


bool Stack :: isEmpty()
{

       if (getHead()==NULL)//empty
           return true;
       else
           return false;
}

// display after a node
void Stack :: displayStarting(LinkedNode *start)
{

    if(start == NULL)
    {
        cout << "End" << endl;
    }
    else
    {
        start->data.printEverything();
        displayStarting(start->next);
    }
}


//display everythinhg
void Stack :: display()
{

    if(getHead() == NULL)
    {
        cout << "NULL Stack." << endl;
    }
    else
    {
        cout << "~Stacks~" << endl;
        getHead()->data.printEverything();
        displayStarting(getHead()->next); 
    }
}

LinkedNode* Stack :: pop()
{
    LinkedNode* temp=NULL;
   //if empty
    if(isEmpty())
    {
        cout << "Empty Stack." << endl;
        return NULL;
    }
    //not empty so pop top
    else
    {
        temp=getHead();
        setHead(getHead()->next);
        return temp;

    }
    //subtract one from count
    setCount(getCountorCountList()-1);
}


LinkedNode* Stack :: peek()
{
    LinkedNode* temp=NULL;
    //if empty
    if(isEmpty())
    {
        cout << "Empty Stack." << endl;
        return NULL;
    }
    //not empty so return the head
    else
    {
        temp=getHead();
        return temp;
    }
}

//display just one node
void Stack :: displayOne(LinkedNode *one)
{
    //if the parameter is null
    if(one == NULL)
    {
        cout << "empty" << endl;
    }

    //print if not empty
    else
    {
        one->data.printEverything();

    }
}


void Stack :: destroyEverything()
{
    LinkedNode* temp= NULL;
    LinkedNode* ptr;
    ptr=getHead();
    //if empty
    if(getHead() == NULL)
    {
        cout << "Empty Already." << endl;
    }
    //not empty so empty it
    else
    {
        {

            while(getHead()->next!=NULL)
            {

                temp=getHead();
                setHead(getHead()->next);
                temp=NULL;

            }
            setHead(NULL);

        }
    }
    setCount(0);
}


int Stack:: getAmount()
{
    //return the count
    return getCountorCountList();
}



 Queue :: Queue()
{
    //set everything empty
        setCount(0);
        setHead(NULL);
        setTail(NULL);

}

bool Queue :: isEmpty()
{
    //is empty??
       if (getHead()==NULL && getTail()==NULL)
           return true;
       else
           return false;
}

 void Queue :: enqueue (LinkedNode* norf)
{
    //if empty
    if (isEmpty())
    {
        setHead(norf);
        setTail(norf);

    }
    //if not empty
    else
    {
        getTail()->next = norf;
        setTail(norf);
    }
    //add 1 to count
    setCount(getCountorCountList()+1);
}

//display starting from a given point
void Queue :: displayStarting(LinkedNode *start)
{

    if(start == NULL)
    {
        cout << "End" << endl;
    }
    else
    {
        start->data.printEverything();
        displayStarting(start->next);
    }
}


//display everything
void Queue :: display()
{

    if(getHead() == NULL)
    {
        cout << "NULL Queue." << endl;
    }
    else
    {
        cout << "~Queue~" << endl;
        getHead()->data.printEverything();
        displayStarting(getHead()->next);
    }
}

//get count
int Queue:: getAmount()
{
    return getCountorCountList();
}


 LinkedNode* Queue :: dequeue()
{
    LinkedNode* temp=NULL;
    //if empty
    if (isEmpty())
    {
        cout << "Empty Queue"<< endl;
        return NULL;
    }
    //if not empty dequeue
    else
    {
        setCount(getCountorCountList()-1);
        if (getTail()==getHead())
        {
            temp = getHead();
            setHead(NULL);
            setTail(NULL);
            return temp;
        }
        else
        {
            temp = getHead();
            setHead(getHead()->next);
            return temp;
        }

    }


}


void Queue :: destroyEverything()
{
    LinkedNode* temp= NULL;
    LinkedNode* ptr;
    ptr=getHead();
    //if empty already
    if(getHead() == NULL)
    {
        cout << "Empty Already." << endl;
    }
    //if not empty empty the queue
    else
    {
        {
            while(getHead()->next!=NULL)
            {

                temp=getHead();
                setHead(getHead()->next);
                temp=NULL;

            }
            setHead(NULL);

        }
    }
    //set count to 0 because the whole thing is being destroyed
    setCount(0);
}

LinkedNode* Queue :: peekFront()
{
    LinkedNode* temp=NULL;
    //if empty
    if(isEmpty())
    {
        cout << "Empty Stack." << endl;
        return NULL;
    }
    //if not empty return the head
    else
    {
        temp=getHead();
        return temp;
    }
}


LinkedNode* Queue :: peekRear()
{
    LinkedNode* temp=NULL;
    //if empty
    if(isEmpty())
    {
        cout << "Empty Stack." << endl;
        return NULL;
    }
    //if not empty return the tail
    else
    {
        temp=getTail();
        return temp;
    }
}
//Display one node
void Queue :: displayOne(LinkedNode *one)
{

    if(one == NULL)
    {
        cout << "empty" << endl;
    }
    else
    {
        one->data.printEverything();

    }
}
