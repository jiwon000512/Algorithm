#include <iostream>

using namespace std;

#define MaxSize 100

int recursiveBst(int a[], int min, int max, int target)
{
    int avg = (min + max) / 2;
    if (min > max)
        return -1;
    else
    {
        if (a[avg] == target)
            return avg;
        else if (a[avg] > target)
            return recursiveBst(a, min, avg - 1, target);
        else
            return recursiveBst(a, avg + 1, max, target);
    }
}

int main()
{
    int numCases, a[MaxSize];

    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int size, target;

        cin >> size >> target;

        for (int j = 0; j < size; j++)
        {
            cin >> a[j];
        }

        cout << recursiveBst(a, 0, size - 1, target) << '\n';
    }
}