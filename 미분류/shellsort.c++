#include <iostream>

using namespace std;

#define MAX_SIZE 1000
void ShellSort(int a[], int n);

int main()
{
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int num;
        int a[MAX_SIZE];

        cin >> num;

        for (int j = 0; j < num; j++)
            cin >> a[j];

        ShellSort(a, num);
    }
}

void ShellSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    int shrinkRatio = 2;
    int gap = n / shrinkRatio;

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = a[i];
            bool stop = false;
            for (int j = i; (j >= gap) || (a[j - gap] > tmp); j -= gap)
            {

                if (a[j - gap] > tmp && j >= gap)
                {
                    a[j] = a[j - gap];
                    a[j - gap] = tmp;
                    countSwaps++;

                    if (!stop)
                        countCmpOps++;
                }
                else if (a[j - gap] <= tmp && j >= gap)
                {
                    if (!stop)
                        countCmpOps++;
                    stop = true;
                }
            }
        }
        gap /= shrinkRatio;
    }

    cout << countCmpOps << ' ' << countSwaps << '\n';
}