#include <iostream>

using namespace std;

#define MaxSize 1000

void quicksort_Hoare(int a[], int low, int high);
void quicksort_Lomuto(int a[], int low, int high);
int partition_Hoare(int a[], int low, int high);
int partition_Lomuto(int a[], int low, int high);
void swap(int *a, int *b);

int numOfSwapH;
int numOfCompH;

int numOfSwapL;
int numOfCompL;

int main()
{
    int numOfCases;
    cin >> numOfCases;

    for (int i = 0; i < numOfCases; i++)
    {
        numOfCompH = numOfCompL = numOfSwapH = numOfSwapL = 0;
        int n, in, h[MaxSize], l[MaxSize];

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> in;
            h[j] = in;
            l[j] = in;
        }
        quicksort_Hoare(h, 0, n - 1);
        quicksort_Lomuto(l, 0, n - 1);
        cout << numOfSwapH << ' ' << numOfSwapL << ' ' << numOfCompH << ' ' << numOfCompL << '\n';
    }
}

void quicksort_Hoare(int a[], int low, int high)
{
    if (low >= high)
        return;

    int p = partition_Hoare(a, low, high);
    quicksort_Hoare(a, low, p);
    quicksort_Hoare(a, p + 1, high);
}

int partition_Hoare(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i = i + 1;
            numOfCompH++;
        } while (a[i] < pivot);
        do
        {
            j = j - 1;
            numOfCompH++;
        } while (a[j] > pivot);

        if (i < j)
        {
            numOfSwapH++;
            swap(a[i], a[j]); // swap 연산
        }
        else
        {
            return j;
        }
    }
}

void quicksort_Lomuto(int b[], int low, int high)
{
    if (low >= high)
        return;
    int p = partition_Lomuto(b, low, high);
    quicksort_Lomuto(b, low, p - 1);
    quicksort_Lomuto(b, p + 1, high);
}

int partition_Lomuto(int b[], int low, int high)
{
    int pivot = b[low];
    int i, j = low;

    for (i = low + 1; i <= high; i++)
    {
        numOfCompL++;
        if (b[i] < pivot) //비교연산
        {
            j++;
            numOfSwapL++;
            swap(b[i], b[j]); // swap연산
        }
    }

    int pivot_pos = j;
    numOfSwapL++;
    swap(b[pivot_pos], b[low]); // swap 연산
    return pivot_pos;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}