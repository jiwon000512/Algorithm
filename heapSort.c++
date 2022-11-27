#include <iostream>

using namespace std;

#define MAX_SIZE 1002

int arr[MAX_SIZE];

int n, ans;

void swap(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void fixHeap(int i, int size)
{
    int vacant, left, right, pre;
    vacant = i;
    do
    {
        left = vacant * 2;
        right = left + 1;
        pre = vacant;

        if(left <= size)
        {
            ans++;
            if(arr[left] > arr[vacant])
                vacant = left;
        }

        if(right <= size)
        {
            ans++;
            if(arr[right] > arr[vacant])
                vacant = right;
        }

        if(vacant != pre)
            swap(vacant,pre);

    } while (vacant != pre);
}

void heapSort()
{
    for (int i = n / 2; i >= 1; i--)
    {
        fixHeap(i, n);
    }

    for (int heapSize = n; heapSize > 1; heapSize--)
    {
        swap(1,heapSize);
        fixHeap(1, heapSize - 1);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int cases = 0; cases < t; cases++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        heapSort();

        cout << ans << '\n';
        ans = 0;
    }
}