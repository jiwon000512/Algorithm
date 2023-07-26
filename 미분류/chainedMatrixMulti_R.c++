#include <iostream>

using namespace std;

int cmm(int d[], int i, int j)
{
    if (i == j)
        return 0;

    int min = 9999999, sum;
    for (int k = i; k < j; k++)
    {
        sum = cmm(d, i, k) + cmm(d, k + 1, j) + d[i - 1] * d[k] * d[j];
        if (sum < min)
            min = sum;
    }

    return min;
}

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int n;
        cin >> n;

        int a[n + 1];

        for (int j = 0; j <= n; j++)
        {
            cin >> a[j];
        }

        cout << cmm(a, 1, n) << '\n';
    }
}