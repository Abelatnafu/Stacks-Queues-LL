//
//  LinkedN&L.hpp
//  Lab 04
//
//  Created by Abel Atnafu on 7/25/20.
//  Copyright © 2020 Abel Atnafu. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>


#ifndef LinkedN_L_hpp
#define LinkedN_L_hpp


struct LinkedNode{

    Dollar data;
    LinkedNode *next;
};


class LinkedList
{
    private:
    //Attributes
    int count;
    LinkedNode *head;
    LinkedNode *tail;

    public:
    //constructor
    LinkedList();
    //destructor
    ~LinkedList();
    /*
     counts amount of members
     pre:
     post
     return:count
     */
    int getCountorCountList();
    /*
    head getter
    pre:
    post
    return:head
    */
    LinkedNode* getHead();
    /*
    tail getter
    pre:
    post
    return:tail
    */
    LinkedNode* getTail();
    /*
    count setter
    pre:int
    post
    return:
    */
    void setCount(int num);
    /*
    head setter
    pre:node ptr
    post
    return:
    */
    void setHead(LinkedNode* starter);
    /*
    tail setter
    pre:node ptr
    post
    return:
    */
    void setTail(LinkedNode* end);

    /*
    append function
    pre : node pointer
    post:adds to the LinkedList
    return:
       */
    void append_node(LinkedNode* newDo);
    /*
    display the whole thing
    pre :
    post:displays everything
    return:
    */
    void display();
    /*
    display starting from a given point
    pre : node pointer
    post:displays starting from the pointer
    return:
    */
    void displayStarting(LinkedNode *start);
    /*
    delete specific node
    pre : node pointer
    post:deletes a specific node
    return:
    */
    void deleteitem (LinkedNode *listitem);
    /*
    search for a node
    pre : node pointer
    post:
    return:the found node ptr
    */
    LinkedNode* findDollar (LinkedNode* mymoney);
    /*
    display the a single node
    pre :node pointer
    post:displays everything
    return:
    */
    void displayOne(LinkedNode *one);
    /*
    Empties everything
    pre :
    post:empties the whole stack
    return:
    */
    void  deleteEverything();
    /*checks if empty
    pre :
    post:
    return:bool empty or not
    */
    bool  isEmpty ();



    

};

#endif /* LinkedN_L_hpp */

LinkedList :: LinkedList ()
{
    //empty everything
    count=0;
    head = NULL;
    tail = NULL ;

}

LinkedList :: ~LinkedList()
{

}
//get count
int LinkedList::  getCountorCountList()
{
    return count;
}

//getter head
LinkedNode* LinkedList:: getHead()
{
    return head;
}

//getter tail
LinkedNode* LinkedList:: getTail()
{
    return tail;
}

//count setter
void LinkedList :: setCount(int num)
{
    count= num;

}

//head setter
void LinkedList :: setHead(LinkedNode* starter)
{
    head= starter;

}

//tail setter
void LinkedList :: setTail(LinkedNode* end)
{
    tail= end;

}


void LinkedList ::append_node(LinkedNode* newDo)
{
    LinkedNode *temp = new LinkedNode;
    LinkedNode*ptr=head;
    temp->data = newDo->data;
    temp->next = NULL;

    //if empty
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }

    //if not empty append
    else
    {
        //append to end
        while(ptr->next!=NULL)
        {
            ptr= ptr->next;
        
        }
        ptr->next = temp;
        ptr= ptr->next;
        tail->next = temp;
        tail = tail->next;
    }
    //add one to count
    count++;
}

//display starting from a point
 void LinkedList :: displayStarting(LinkedNode *start)
{
    //if empty
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

//display a node
void LinkedList :: displayOne(LinkedNode *one)
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

//display eberything
 void LinkedList :: display()
{

    if(head == NULL)
    {
        cout << "NULL Linked list" << endl;
    }
    else
    {
        cout << "~Linked Lists~" << endl;
        head->data.printEverything();
        displayStarting(head->next);
    }
}


// delete a specific node
void LinkedList :: deleteitem (LinkedNode *listitem)
{
    Dollar money= listitem->data;
    //if empty
    if (head==NULL)
    {
        cout<<"Empty list"<<endl;
    }
    //if not empty delete the nod
    else if (head!=NULL)
    {
        //if head the node
        if (head->data==money)
        {
            head=head->next;
            count--;
        }
        //if head isnt the nod
        else
        {
            LinkedNode* temp=NULL;
            LinkedNode* prevptr=head;
            LinkedNode* curr=head->next;
            while (curr !=NULL)
            {

                if (curr->data==money)
                {

                    temp = curr;
                    curr=NULL;
                    count--;
                }
                else
                {
                    prevptr=prevptr->next;
                    curr=curr->next;
                }
            }

                if (temp!=NULL)
                {
                    prevptr->next=temp->next;
                }
                else
                {
                    cout<< "Doesn't exist" <<endl;
                }

        }
    }
}


//search for a node
LinkedNode* LinkedList :: findDollar (LinkedNode* mymoney)
{
    LinkedNode* temp= NULL;
    LinkedNode* ptr =head;

    while (ptr!=NULL)
    {
        if (ptr->data == mymoney->data)
        {
            temp= ptr;
            return temp;
        }
        ptr= ptr->next;
    }
    return temp;
}

//check if empty
bool LinkedList :: isEmpty ()
{
    bool isEmpty = false;

    if (head== NULL)
    {
        isEmpty = true;
    }
     return isEmpty;
}

//deletes the whole Linked List
void LinkedList :: deleteEverything()
{

    LinkedNode* temp=NULL;
    LinkedNode* ptr=head;

    //if empty
    if(ptr == NULL)
    {
        cout << "NULL" << endl;
    }
    //if not empty
    else
    {
        while(ptr->next!=NULL)
        {

            temp=ptr->next;
            ptr->next=temp->next;


        }
        head= NULL;

    }
    count=0;
}

