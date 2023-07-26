#include <iostream>

using namespace std;

#define MaxSize 100

int mergeSortIterative(int v[], int n);
int merge(int v[], int low, int mid, int high);
int min(int a, int b);

int main()
{
    int numTestCases;

    cin >> numTestCases;

    for(int i=0; i<numTestCases; i++)
    {
        int n ,v[MaxSize];
        cin >> n;

        for(int j=0; j<n; j++)
        {
            cin >> v[j];
        }

        cout << mergeSortIterative(v, n) << '\n';
    }
}

int mergeSortIterative(int v[], int n)
{
    int size = 1;
    int ans = 0;

    while(size < n)
    {
        for(int i=0; i<n; i+=2*size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = min(i + 2 * size -1 , n -1);

            if(mid >= n-1)
                break;
            ans += merge(v, low, mid, high);
        }
        size *= 2;
    }
    
    return ans;
}

int merge(int v[], int low, int mid, int high)
{
    int i, j, k, ans = 0;
    int tmp[MaxSize];

    for(i = low; i<=high; i++)
        tmp[i] = v[i];
    
    i = k = low;
    j = mid + 1;

    while(i <= mid && j <= high)
    {
        if(tmp[i] <= tmp[j])
            v[k++] = tmp[i++];
        else
            v[k++] = tmp[j++];
        
        ans ++;
    }

    while(i<=mid)
        v[k++] = tmp[i++];
    while(j<=high)
        v[k++] = tmp[j++];
    
    return ans;
}

int min(int a, int b)
{
    return a >= b ? b : a;
}