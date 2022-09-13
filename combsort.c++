#include <iostream>

using namespace std;

#define MAX_SIZE 1000
void combSort(int a[], int n);

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

        combSort(a, num);
    }
}

void combSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    int gap = n;
    float shrink = 1.3;
    bool sorted = false;

    while (!sorted)
    {
        if(gap <= 1)
        {
            gap = 1;
            sorted = true;
        }

        int i = 0;
        while (i + gap < n)
        {
            countCmpOps++;
            if (a[i] > a[i + gap])
            {
                countSwaps++;
                int tmp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = tmp;
                sorted = false;
            }
            i++;
        }
        gap = gap/shrink;
    }
    
    cout << countCmpOps << ' ' << countSwaps << '\n';
}