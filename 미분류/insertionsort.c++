#include <iostream>

using namespace std;

#define MAX_SIZE 1000
void insertionSort(int a[], int n);

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
        {
            cin >> a[j];
        }

        insertionSort(a, num);
        cout << '\n';
    }
}

void insertionSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    for (int i = 1; i < n; i++)
    {
        int tmp = a[i];
        bool stop = false;
        for (int j = i; j > 0 || a[j - 1] > tmp; j--)
        {
            if (a[j - 1] > tmp)
            {
                countSwaps++;
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                if(!stop)
                {
                    countCmpOps++;
                }
            }
            else
            {
                if(!stop)
                    countCmpOps++;
                stop = true;
            }
        }
    }
    cout << countCmpOps << ' ' << countSwaps << ' ';

    /*
    for(int i=0; i<n; i++)
    {
        cout << " " << a[i];
    }
    */
}