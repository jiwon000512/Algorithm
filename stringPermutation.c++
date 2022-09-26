#include <iostream>

using namespace std;

void stringPermute(char a[], int begin, int end);
void checkWeight(char a[]);

int numOfPWeight, aSize;

int main()
{
    int caseNum;
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        char arr[10];
        aSize = 0, numOfPWeight = 0;
        cin >> arr;

        for (int j = 0; arr[j]; j++)
            aSize++;

        stringPermute(arr, 0, aSize);

        cout << numOfPWeight << '\n';
    }
}

void swap(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

void stringPermute(char a[], int begin, int end)
{
    int range = end - begin;

    if (range == 1)
    {
        checkWeight(a);
    }
    else
    {
        for (int i = 0; i < range; i++)
        {
            swap(a[begin], a[begin + i]);
            stringPermute(a, begin + 1, end);
            swap(a[begin], a[begin + i]);
        }
    }
}

void checkWeight(char *a)
{
    int weight = 0;
    int sign = 1;
    for (int i = 0; i < aSize; i++)
    {
        weight += (a[i] - 'a') * sign;
        sign *= -1;
    }

    if (weight > 0)
    {
        numOfPWeight++;
    }
}
