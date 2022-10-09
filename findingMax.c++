#include <iostream>

using namespace std;

#define MAX_SIZE 100

int MAX(int a, int b)
{
    return a > b ? a : b;
}

int recurMax(int a[], int left, int right)
{
    int half;

    if (left == right)
        return a[left];
    else
    {
        half = (left + right) / 2;
        return MAX(recurMax(a, left, half),
                   recurMax(a, half + 1, right));
    }
}

int main()
{
    int a[MAX_SIZE], numCases;

    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++)
        {
            cin >> a[j];
        }

        cout << recurMax(a, 0, size - 1) << '\n';
    }
}