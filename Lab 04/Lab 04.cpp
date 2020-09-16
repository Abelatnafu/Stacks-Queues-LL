/*
Name: Abel Atnafu
Class: CIS 22C
Lab 02

 This program lets you intput an array of your preferred type and sorts it for you by merge sort system.

 */
/*
                Pseudocode


print(NameBox);

Create 7 Dollar objects;

Create 7 LinkedNode objects with Dollar data in them;

    //Linked list
Create a linkedList object;

append_node(firstNode);
append_node(secondNode);
append_node(thirdNode);
delete_node(thirdNode);
append_node(fourthNode);
append_node(fifthNode);

DisplayTheLinkedList( );
Show the amount of members in LinkedList;
Find(secondNode) then append_node to the list;

DisplayTheLinkedList();
Check isEmpty or not();

EmptyTheLinkedList();
DisplayTheLinkedList();
Check isEmpty or not();
DisplayTheLinkedList();


    //Stacks

Create Stack object;

PushPrice(firstNode);
PushPrice(secondNode);
PushPrice(thirdNode);
PushPrice(fourthNode);
pop(): //remove top of the stack
peek() and output the top of the stack;

DisplayTheStack();
EmptyTheStack();
DisplayTheStack();



    //Queue
Create Queue object;

Enqueue(firstNode);
Enqueue(secondNode);
Enqueue(thirdNode);
Enqueue(fourthNode);
Dequeue(); //removes and returns the firstNode
Enqueue(fifthNode);
DisplaytheQueue();


peekFront() and output the front;
peekRear() and output the rear;

EmptytheQueue();

DisplaytheQueue();


Return0;


*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Dollar.hpp"
#include "LinkedN&L.hpp"
#include "Stack&Queue.hpp"

int main()
{
       cout<< left<< fixed<< setw(18)<<"****************************************"<<endl;
       cout<< left<< fixed<< setw(18)<<"Name: Abel Atnafu"<<endl;
       cout<< left<< fixed<< setw(18)<<"Summer CIS 22C"<<endl;
       cout<< left<< fixed<< setw(18)<<"Lab 02"<<endl;
       cout<< left<< fixed<< setw(18)<<"****************************************"<<endl;


    Dollar soda(2,99,"USD","USC");
    Dollar pizza(10,49,"USD","USC");
    Dollar drugs(49,99,"USD","USC");
    Dollar lolipop(2,49,"USD","USC");
    Dollar clothes(40,00,"USD","USC");
    Dollar car(3000,13,"USD","USC");
    Dollar shoes(250,51,"USD","USC");

    LinkedNode sodaNode={soda, NULL};
    LinkedNode pizzaNode={pizza, NULL};
    LinkedNode drugsNode={drugs, NULL};
    LinkedNode lolipopNode={lolipop, NULL};
    LinkedNode clothesNode={clothes, NULL};
    LinkedNode carNode={car, NULL};
    LinkedNode shoesNode={shoes, NULL};


                //LinkedList Demoastration
    cout<<"********LinkedList Demoastration********"<<endl<<endl;
    LinkedList linked;

    cout << "       *Appending soda price."<<endl;
    linked.append_node(&sodaNode);
    cout << "       *Appending pizza price."<<endl;
    linked.append_node(&pizzaNode);
    cout << "       *Appending drug price."<<endl;
    linked.append_node(&drugsNode);
    cout << "       -Delete Drug price."<<endl;
    linked.deleteitem(&drugsNode);
    cout << "       *Displaying the whole Linked List."<<endl;
    linked.display();
    cout << "       *Appending lolipop price."<<endl;
    linked.append_node(&lolipopNode);
    cout << "       *Appending Clothes price."<<endl;
    linked.append_node(&clothesNode);

    cout << "       *Displaying the whole Linked List."<<endl;
    linked.display();

    cout << "       #Amount of Members in list."<<endl;
    cout <<"We have " <<linked.getCountorCountList()<< " members."<<endl;

    cout << "       @Searches for Pizza price in list and adds it to the end of the list."<<endl;
    linked.append_node(linked.findDollar(&pizzaNode));

    cout << "       *Displaying the whole Linked List."<<endl;
    linked.display();

    cout << "       ?Check if the list is empty or not?"<<endl;
    if (linked.isEmpty())
         cout << "The list is empty"<<endl;
    else
        cout << "The list is not empty"<<endl;

     cout << "       0Empty the list."<<endl;
    linked.deleteEverything();

    cout << "       *Displaying the whole Linked List."<<endl;
    linked.display();

    cout << "       ?Check if the list is empty or not?"<<endl;
       if (linked.isEmpty())
            cout << "The list is empty"<<endl;
       else
           cout << "The list is not empty"<<endl;

    cout << "       *Displaying the whole Linked List."<<endl;
    linked.display();
      cout<<endl<<endl;

                    //Stack Demonastration
     cout<<"********Stack Demoastration********"<<endl<<endl;

    Stack stackList;

    cout << "       *Pushing pizza price."<<endl;
    stackList.pushDollar(&pizzaNode);
    cout << "       *Pushing drug price."<<endl;
    stackList.pushDollar(&drugsNode);
    cout << "       *Pushing car price."<<endl;
    stackList.pushDollar(&carNode);
    cout << "       *Pushing shoes price."<<endl;
    stackList.pushDollar(&shoesNode);
    cout << "       -Poping shoes price."<<endl;
    stackList.pop();
    cout << "       @Finds  the top of the Stack and outputs it."<<endl;
    stackList.displayOne(stackList.peek());

    cout << "       *Displaying the whole Stack."<<endl;
    stackList.display();

    cout << "       0Empty the Stack."<<endl;
    stackList.destroyEverything();

    cout << "       *Displaying the whole Stack."<<endl;
    stackList.display();
    cout<<endl<<endl;


                //Queue Demonastration
    cout<<"********Queue Demoastration********"<<endl<<endl;
    Queue quelist;

       cout << "       *Enqueueing pizza price."<<endl;
        quelist.enqueue(&pizzaNode);
       cout << "       *Enqueueing drug price."<<endl;
        quelist.enqueue(&drugsNode);
       cout << "       *Enqueueing car price."<<endl;
        quelist.enqueue(&carNode);
       cout << "       *Enqueueing shoes price."<<endl;
        quelist.enqueue(&shoesNode);
       cout << "       -Dequeueing pizza price."<<endl;
        quelist.dequeue();
       cout << "       *Enqueueing clothes price."<<endl;
        quelist.enqueue(&clothesNode);

       cout << "       *Displaying the whole Queue."<<endl;
        quelist.display();


       cout << "       @Finds  the top of the Queue and outputs it."<<endl;
        quelist.displayOne(quelist.peekFront());
       cout << "       @Finds  the rear of the Queue and outputs it."<<endl;
        quelist.displayOne(quelist.peekRear());

       cout << "       0Empty the Queue."<<endl;
        quelist.destroyEverything();

       cout << "       *Displaying the whole Queue."<<endl;
        quelist.display();
    




    return 0; 
}
