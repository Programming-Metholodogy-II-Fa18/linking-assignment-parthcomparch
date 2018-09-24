//
// Created by Parth Patel on 9/23/2018.
//

#ifndef PM2QUESTION3_SORTING_H
#define PM2QUESTION3_SORTING_H
#pragma once
#include<iostream>
using namespace std;
struct node
{
   int data;
    node *next;
};

class linkedList {
   node *head;

public:
    linkedList();

    void Push(int data);

    void Pop();

    int Peek();

    void insertionSort();

    void print();
    };
#endif //PM2QUESTION3_SORTING_H
