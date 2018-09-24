//
// Created by Parth Patel on 9/23/2018.
//
#include "ArbitraryQueueArray.h"
ArbitraryQueueArray::ArbitraryQueueArray() {
    First =-1;
}

bool ArbitraryQueueArray::isEmpty(){
    {
        return First == -1;
    }
}
void ArbitraryQueueArray::Enqueue(int obj)// Insert at the tail of the list.
{
    First = First +1;
    array[First] =obj;

}
void ArbitraryQueueArray::Push(int obj)// Insert at the head of the list.
{
    if(First>=(Max-1)){
        cout<<"\nArray is full..";
    }
    else {
        int newFirst = First + 1;
        while (First != -1) {
            array[First + 1] = array[First];
            First = First - 1;
        }
        array[0] = obj;
        First = newFirst;
    }
}
int ArbitraryQueueArray::Dequeue()// remove at the tail of the list.
{
    if(isEmpty())
    {
        cout<<"\nArray is Empty";
    }
    else {
        int temp = array[First];
        array[First] = NULL;
        First = First - 1;
        return temp;
    }
}
int ArbitraryQueueArray::Pop()// remove at the head of the list.
{
    if(isEmpty()){
        cout<<"\nArray is empty..";
    }
    else {
        int tmp = array[0];
        int temp =-1;
        while (temp != First) {
            array[temp + 1] = array[temp+2];
            temp = temp + 1;
        }
        First = First-1;
        cout<<"\nRemoves.."<<tmp;
        return tmp;
    }
}
void ArbitraryQueueArray::ShowList()
{

    if(isEmpty()){
        cout<<"\nThe list is empty.";
    }
    else {
        cout<<"\nThe List contains: ";
        for(int i=0; i<=First; i++)
        {
            cout<<array[i]<<" ";
        }
    }
}
int ArbitraryQueueArray::Traverse(int i)
{
    if(isEmpty()){
        cout<<"\nThe list is empty.";
    }
    else {
        return array[i];
    }
}
