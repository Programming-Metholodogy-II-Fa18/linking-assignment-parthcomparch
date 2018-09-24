//
// Created by Parth Patel on 9/23/2018.
//
#include <iostream>
#include"sorting.h"

linkedList::linkedList()
{
    head = nullptr;
}

void linkedList::Push(int data) {
    node *NewNode,*Temp;
    NewNode = new node;
    NewNode->data = data;
    NewNode->next = nullptr;
        if (head == nullptr)
         {
            head = NewNode;
         }

        else
        {
        Temp = head;
        head = NewNode;
        head->next = Temp;
        }
}

 void linkedList::Pop(){
       node *tmp = head;
       head = head->next;
       delete tmp;
       }

       int linkedList::Peek()
{
       return head->data;
}

void linkedList::insertionSort()
{
    if (head == NULL || head->next == NULL)
        return ;
    node *newNode = new node;
    newNode->data = head->data;
    newNode->next = NULL;
    node *cur = head->next;
//go through each element in loop
    while (cur != NULL)
    {
//insert the elements into new list
        node *pointer1 = newNode;
        node *next = cur->next;
//data at head less than equal to next node data
        if (cur->data <= newNode->data)
        {
            node *head1 = newNode;
            newNode = cur;
            newNode->next = head1;
        }

        else
        {
            while (pointer1->next != NULL)
            {
                if (cur->data > pointer1->data && cur->data <= pointer1->next->data)
                {
                    node *next1= pointer1->next;
                    pointer1->next = cur;
                    cur->next = next1;
                }
                pointer1 = pointer1->next;
            }
            if (pointer1->next == NULL && cur->data > pointer1->data)
            {
                pointer1->next = cur;
                cur->next = NULL;
            }
        }
        cur = next;
    }
    head= newNode;
}
void linkedList::print()
{
    node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " " << endl;
        cur = cur->next;
    }
   cout << endl;
}
int linkedList::size()
{
    node *cur = head;
    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

