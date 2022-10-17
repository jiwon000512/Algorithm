#include <iostream>

using namespace std;

#define MAX_SIZE 1000
void selectionSort(int a[], int n);

int main()
{
    int numTestCases;
    cin >> numTestCases;

    for(int i=0; i<numTestCases; i++)
    {
        int n;
        int a[MAX_SIZE];

        cin >> n;
        for(int j=0; j<n; j++)
            cin >> a[j];

        selectionSort(a, n);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    for(int i=0; i<n-1; i++)
    {
        int imin = i;

        for(int j=i+1; j<n; j++)
        {
            countCmpOps++;
            if(a[j] < a[imin])  
                imin = j;
        }

        if(imin != i)
        {
            countSwaps++;
            swap(a[imin], a[i]);
        }
    }

    cout << countCmpOps << ' ' << countSwaps << '\n';
}