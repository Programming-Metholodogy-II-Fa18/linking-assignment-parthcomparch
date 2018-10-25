#include<iostream>
#include <cmath>
#include <string>
using namespace std;
int intialSize;
//Load main function using pointers to implement the code.
//I could have used vectors but it would make stuff harder.
class DaryHeap
{
private:
    int numkids;
    int size;
    int *arr;
public:

    DaryHeap(int d)
    {
        intialSize = 0;
        numkids = d;
        size = 10;
        arr = new int[size];

    }
    //for input values greater than 10.
    //Implementing double array ny copying the elements
    void doubleArray() {
        int new_size = 2 * size;
        int *copying;

        copying = new int[new_size];
        for (int i = 0; i < size; i++) {
            copying[i] = arr[i];
        }

        arr = copying;

    }
    void sink(int k)
    {
        int MaxchildLocal = 0;
        int *child;
        int tmp;
        child = new int[numkids + 1];

        while (1)
        {

            for (int i = 1; i <= numkids; i++){
                if ((numkids*k + i) < intialSize) {
                    child[i] = (numkids*k + i);
                }
                else {

                    child[i] = -1;
                }
            }

            int Maxchild = -1;

            for (int i = 1; i <= numkids; i++)
            {
                if (child[i] != -1 && arr[child[i]] > Maxchild)
                {
                    MaxchildLocal = child[i];
                    Maxchild = arr[child[i]];
                }
            }

            if (Maxchild == -1)
                break;
//swapping arr[k] and arr[MaxchildLocal]
             if (arr[k] < arr[MaxchildLocal]) {
                tmp = arr[k];
                arr[k] = arr[MaxchildLocal];
                arr[MaxchildLocal] = tmp;
            }
            k = MaxchildLocal;
        }
    }

    void sinkSort(int a[], int length)
    {
        int MaxchildLocal = 0;
        int *child;
        int k = 0;
        int tmp2;
        child = new int[numkids + 1];

        while (1)
        {

            for (int i = 1; i <= numkids; i++) {
                if ((numkids*k + i) < length) {
                    child[i] = (numkids*k + i);
                }
                else {

                    child[i] = -1;
                }
            }

            int Maxchild = -1;

            for (int i = 1; i <= numkids; i++)
            {
                if (child[i] != -1 && a[child[i]] > Maxchild)
                {
                    MaxchildLocal = child[i];
                    Maxchild = a[child[i]];
                }
            }

            if (Maxchild == -1)
                break;
//swapping arr[k] and arr[MaxchildLocal]
            if (a[k] < a[MaxchildLocal]) {
                tmp2 = a[k];
                a[k] = a[MaxchildLocal];
                a[MaxchildLocal] = tmp2;

            }
            k = MaxchildLocal;
        }
    }


    void swim(int k)
    {

        int parent = (k - 1)/numkids;
        int tmp;
        while (parent >= 0)
        {
            //swapping(arr[k], arr[parent]);
            if (arr[k] > arr[parent])
            {
                tmp = arr[k];

                arr[k] = arr[parent];
                arr[parent] = tmp;
                k = parent;
                parent = (k - 1) / numkids;
            }
            else
                break;
        }
    }



    void insert(int k)
    {

        if (intialSize == size) {
            cout << "intiated increase" << endl;
            doubleArray();
            size = size * 2;
        }
        arr[intialSize] = k;

        intialSize = intialSize + 1;

        swim(intialSize-1);
    }


    int* daryHeapsort()
    {
        int tmp;
        int *Heap;
        Heap = new int[intialSize - 1];
        for (int i = 0; i <= intialSize - 1; ++i) {
            Heap[i]=arr[i];
        }
        for (int i = intialSize - 1; i >= 0; i--)
        {
            tmp = Heap[0];
            Heap[0] = Heap[i];//swapping Heap[0] and Heap[i]
            Heap[i] = tmp;
            sinkSort(Heap, i);
        }
        return Heap;
    }

    int delMax()
    {
        int max = arr[0];
        arr[0] = arr[intialSize - 1];

        intialSize = intialSize - 1;
        sink(0);

        return max;
    }
    void displayout() {

        for (int i = 0; i <= intialSize-1; ++i) {
            cout << arr[i] << endl;
        }
    }
};
