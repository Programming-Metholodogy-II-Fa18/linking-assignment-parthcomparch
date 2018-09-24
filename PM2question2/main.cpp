#include <iostream>
#include "ArbitraryQueueArray.h"
using namespace std;

int main() {
    ArbitraryQueueArray n;
    n.Push(1);
    n.Push(2);
    n.Push(3);
    n.ShowList();
    n.Enqueue(1);
    n.Enqueue(9);
    n.Enqueue(3);
    n.ShowList();
    n.Push(5);
    n.ShowList();
    n.Dequeue();
    n.Dequeue();
    n.Dequeue();
    n.ShowList();
    cout<<endl;
    n.Pop();
    n.ShowList();
    return 0;
}