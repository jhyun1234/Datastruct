
#include <iostream>
#include "SinglelinkedList.h"

using namespace std;
#pragma region 단일 연결 리스트

    // 1. 단일 연결 리스트 노드 제작 
   
struct Node
{
    int data;
    Node* next;


};



#pragma endregion

void PushFront(Node * target, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = target->next;
    target->next = newNode;

    
}
void Remove(Node* target)
{
    Node* deleteNode = target->next;
    target->next = deleteNode->next;
    delete deleteNode;



}





int main()
{
    SinglelinkedList<int> list;

    list.PushFront(10);
    list.PushFront(20);
    list.PopFront();
    cout << "list 의 사이즈 : " << list.Size() << endl;

    list.DisPlay();

    
}

