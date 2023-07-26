#include <iostream>

using namespace std;

#define MaxSize 100

int ans;

void merge(int a[], int low, int mid, int high)
{
    int tmp[MaxSize];

    for (int i = low; i <= high; i++)
        tmp[i] = a[i];

    int i, j, k;

    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];

        ans++;
    }

    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}

void mergeSort(int v[], int low, int high)
{
    int mid;
    if (low == high)
        return;
    mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}

int main()
{
    int numCases, a[MaxSize];

    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int size;

        cin >> size;

        for (int j = 0; j < size; j++)
        {
            cin >> a[j];
        }

        mergeSort(a, 0, size-1);
        cout << ans << '\n';

        ans = 0;
    }
}