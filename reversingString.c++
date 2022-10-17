#include <iostream>

using namespace std;

void reverseArray(char a[], int i, int j);

int main()
{
    int caseNum;
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        char arr[100];
        int aSize = 0;
        cin >> arr;

        for (int j = 0; arr[j]; j++)
            aSize++;

        reverseArray(arr, 0, aSize - 1);
        cout << arr << '\n';
    }
}

void swap(char a[], int i, int j)
{
    char tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void reverseArray(char a[], int i, int j)
{
    if (i < j)
    {
        swap(a, i, j);
        reverseArray(a, i + 1, j - 1);
    }
}
