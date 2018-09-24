//
// Created by Parth Patel on 9/23/2018.
//
#ifndef PM2QUESTION2_ARBITRARYQUEUEARRAY_H
#define PM2QUESTION2_ARBITRARYQUEUEARRAY_H
#include <iostream>
using namespace std;
#define Max 100
class ArbitraryQueueArray {
private:
    int array[Max];
    int First;
public:
    ArbitraryQueueArray();
    bool isEmpty();
    void Push(int);
    void Enqueue(int);
    int Pop();
    int Dequeue();
    int Traverse(int);
    void ShowList();
};
#endif //PM2QUESTION2_ARBITRARYQUEUEARRAY_H
