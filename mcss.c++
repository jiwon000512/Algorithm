#include <iostream>

using namespace std;

#define MaxSize 100

int big(int a, int b)
{
    return a > b ? a : b;
}

int mcssKadane(int a[], int n, int &startIndex, int &endIndex)
{

    int max = 0 , tmp = 0;

    startIndex = endIndex = -1;

    for (int i = 0, j = 0; j < n; j++)
    {
        tmp += a[j];
        if(tmp > max)
        {
            max = tmp;
            startIndex = i;
            endIndex = j;
        }   
        else if(tmp <= 0)
        {
            i = j + 1;
            tmp = 0;
        }   
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