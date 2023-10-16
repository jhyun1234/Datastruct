#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DoublelinkedList
{
private:


    struct Node
    {
        T data;
        Node* next;
        
    };

    int size;
    Node* head;
    Node* tail;

public:
    CireclelinkedList()
    {

        size = 0;
        head = nullptr;


    }
    void PushFront(T data)
    {

        Node* newNode = new Node;

        newNode->data = data;
        
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;

        }
        else
        {

            newNode->next = head->next;

            head->next->newNode;

        }
        size++;
    }

    void PushBack(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;

        }
        else
        {
            newNode->next = head->next;
            head->next=newNode;

            head = nweNode;

        }
        size++;
    }

    void PopBack()
    {
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;

            return;
        }

        Node* deleteNode = head;
        Node* currentNode = head;

        if (size == 1)
        {
            delete deleteNode;

            head = nullptr;

        }
        else
        {
            for (int i = 0; i < size - 1; i++)
            {

                currentNode = currentNode->next;
            }

            currentNode->next = head->next;

            head = currentNode;

            delete deleteNode;
        }
        size--;
            
          
        
    }

    void PopFront()
    {
        if (head == nullptr)
        {
            cout << "List is Emoty" << endl;

            return;

        }
        if (size == 1)
        {
            Node* deleteNode = head->next;

            delete deleteNode;

            head = nullptr;

        }
        else 
        {
            Node* deleteNode = head->next;

            head->next = deleteNode->next;

            delete deleteNode;

            Node* currentNode = head;

        }
        

        size--;



    }

    ~CireclelinkedList()
    {
        {
            while (head != nullptr)
            {
                Node* deleteNode = head;
                head = head->next;

                delete deleteNode;

            }


        }

    }
};