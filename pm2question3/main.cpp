#include<iostream>
#include"sorting.h"
using namespace std;


int main() {
    int p; char n[p];
        cout << "No. of Inputs needed";

        cin >> p;

    linkedList list;

    std::cout << "please enter the numbers here: ";
    std::cin >> n;
    list.Push(n[p]);


    cout << "Before sorting: " << endl;
    list.print();
    list.insertionSort();
    cout << "After sorting: " << endl;
    list.print();
    cout << "Peek: " << list.Peek() << " \ndata " << list.Peek() << " is popped" << endl;
    list.Pop();
    cout << "Peek: "
         << list.Peek()
         << "\ndata "
         << list.Peek()
         << " is popped"
         << endl;

    list.Pop();

    cout << "Peek: " << list.Peek() << endl;
}
