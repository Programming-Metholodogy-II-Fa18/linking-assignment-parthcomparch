#include<iostream>

using namespace std;
int *sorted;
int count;
class Node {
public:
    int value;
    Node *left;//smaller value than the parent value.
    Node *right;//greater value than the parent value.
    Node *parent;
    Node() {
        value = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class BST {
public:

    BST() {
    }
