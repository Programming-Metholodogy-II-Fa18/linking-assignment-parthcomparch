#include <iostream>

using namespace std;
// Fills prefix sum array
void Sum(const int arr[], int j, int Sum[])
{
    Sum[0] = arr[0];

    // Adding present element
    // with previous element
    for (int i = 1; i < j; i++)
        Sum[i] = Sum[i-1] + arr[i];
}
int main()
{
    int p; char n[p];
    cout << "No. of Inputs needed";

    cin >> p;
    std::cout << "please enter the numbers here: ";
    std::cin >> n;
    int arr[] = { 10, 4, 16, 20 };
    int i = sizeof(arr) / sizeof(arr[0]);
    int Sum[p];

    Sum(arr, p, Sum);
    for (int p = 0; i < p; i++)
        cout << Sum[i] << " ";
}

