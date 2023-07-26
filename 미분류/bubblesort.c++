#include <iostream>

using namespace std;

#define MAX_SIZE 1000
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int num;
        int a[MAX_SIZE], b[MAX_SIZE];

        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> b[j];

        copyArray(a, b, num);
        bubbleSort(a, num);

        copyArray(a, b, num);
        bubbleSortImproved1(a, num);

        copyArray(a, b, num);
        bubbleSortImproved2(a, num);
        cout << '\n';
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            countCmpOps++;
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                countSwaps++;
            }
        }
    }

    cout << countCmpOps << ' ' << countSwaps << ' ';
}

void bubbleSortImproved1(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    bool swapped = false;

    for (int i = 1; i < n; i++)
    {
        swapped = false;
        for (int j = 1; j <= n - i; j++)
        {
            countCmpOps++;
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                countSwaps++;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    cout << countCmpOps << ' ' << countSwaps << ' ';
}

void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    int lastSwappedPos = n;

    while (lastSwappedPos > 0)
    {
        int swappedPos = 0;
        for (int i = 1; i < lastSwappedPos; i++)
        {
            countCmpOps++;
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                swappedPos = i;
                countSwaps++;
            }
        }
        lastSwappedPos = swappedPos;
    }

    cout << countCmpOps << ' ' << countSwaps;
}

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}