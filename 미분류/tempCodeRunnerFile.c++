<<<<<<< HEAD
#include <iostream>

using namespace std;

#define MaxSize 100

int big(int a, int b)
{
    return a > b ? a : b;
}

int mcssKadane(int a[], int n, int &startIndex, int &endIndex)
{
    int max = -1001, tmp[MaxSize];

    startIndex = 0;
    endIndex = 0;

    tmp[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        int tmpStartIndex = startIndex;

        tmp[i] = big(tmp[i - 1] + a[i], a[i]);
        startIndex = (tmp[i] == a[i] ? i : startIndex);

        if (a[i] == 0 && tmp[i] == a[i])
            continue;

        int tmpValue = max;
        max = big(max, tmp[i]);
        startIndex = (max == tmp[i] && max != tmpValue ? startIndex : tmpStartIndex);
        endIndex = (max == tmp[i] && max != tmpValue ? i : endIndex);
    }

    if (max < 0)
    {
        max = 0;
        startIndex = -1;
        endIndex = -1;
    }

    return max;
}

int main()
{
    int numCases;

    cin >> numCases;

    int a[MaxSize];

    for (int i = 0; i < numCases; i++)
    {
        int n, startIndex, endIndex;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }

        cout << mcssKadane(a, n, startIndex, endIndex) << ' ' << startIndex << ' ' << endIndex << '\n';
    }
}
=======
else
>>>>>>> bfd266e (20221017)
