#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }
    void addNote()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student";
        cin >> nim;

        // Step 1 : Allocate memory for new node
        Node *newNode = new Node();

        // step 2 : Assign value to the data field
        newNode->noMhs = nim;

        // step 3 : Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // step 4 : newNode.next = START
            newNode->next = START;

            // step 5 : start.prev = newNode (if start exists)
            if (START != NULL)
                START->prev = newNode;

            // step 6 : newNode.prev = NULL
            newNode->prev = NULL;

            // step 7 : START = newNode
            START = newNode;
            return;
        }
        // insert in between node
        // step 8 : locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll number not allowed" << endl;
            return;
        }

        // step 9 : insert between current and cerrent->next
        newNode->next = current->next; // step 9a
        newNode->prev = current;       // step 9b

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c

        current->next = newNode; // step 9d: current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollno;
        cin >> rollno;

        Node *current = NULL;
        // step 1 : Traverse the list to find the node
        while (current != NULL && current->noMhs != rollno)
            current = current->next;

        if (current == NULL)
        {
        }
        {
            cout << "Record not found" << endl;
            return;
        }

        // step 2 : if node is at beginning
        if (current == START)
        {
            START = current->next; // step 2a : START = START.next
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            // step 3 : Link previous node to the next current
            current->prev->next = current->next;

            // step 4 : if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // step 5 Delete the node
        delete current;
        cout << "Record with roll number " << rollno << "deleted" << endl;
    }
    void transverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // step 1 : Mark first node as currentNode
        Node *currentNode = START;

        // step 2 : Repeat until currentNode == NULL
        cout << "\nRecords in ascending order od roll number are: \n ";
        int i = 0;
        while (currentNode != NULL)
        {

            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // step 3 : move to the next node
            currentNode = currentNode->next;
            i++;
        }
    }
    void revtransverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // step 1 : Move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollno;
        cout << "\nEnter the roll number to serach:";
        cin >> rollno;

        Node *current = START;
        // step 1 : Traverse to find matching roll number while (current != NULL && current->noMhs != rollno)
        current = current->next;
        // step 2: output result
        if (current == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll Number: " << current->noMhs << endl;
        }
    }
