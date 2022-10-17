#include <iostream>

using namespace std;

#define MaxSize 100

int max(int a, int b)
{
    return a > b ? a : b;
}

int findMid(int a[], int start, int mid, int end)
{
    int leftMax = -1001, tmp = 0;
    for (int i = mid; i >= start; i--)
    {
        tmp += a[i];
        leftMax = max(tmp, leftMax);
    }
    int rightMax = -1001;
    tmp = 0;
    for (int i = mid + 1; i < end; i++)
    {
        tmp += a[i];
        rightMax = max(tmp, rightMax);
    }

    return rightMax + leftMax;
}

int mcssDC(int a[], int start, int end)
{

    if (start + 1 == end)
    {
        return a[start];
    }

    int mid = (start + end) / 2;
    int left = mcssDC(a, start, mid);
    int right = mcssDC(a, mid, end);
    int middle = findMid(a, start, mid, end);
    return max(middle, max(left, right));
}

int main()
{
    int numCases;

    cin >> numCases;

    int a[MaxSize];

    for (int i = 0; i < numCases; i++)
    {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        int ans = mcssDC(a, 0, n);
        ans = ans < 0 ? 0 : ans;
        cout << ans << '\n';
    }
}