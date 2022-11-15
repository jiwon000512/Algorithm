#include <iostream>

using namespace std;

#define MAX_SIZE 101

int memo[MAX_SIZE][MAX_SIZE];

char a[MAX_SIZE];
char b[MAX_SIZE];

int max(int a, int b)
{
    return a > b ? a : b;
}

int lcsR(int m, int n)
{

        if(a[m] == '\0' || b[n] == '\0')
        {
            return 0;
        }
        else if(a[m] == b[n])
        {
            return lcsR(m+1,n+1)+ 1;
        }
        else
        {
            return max(lcsR(m + 1, n), lcsR(m, n + 1));
        }
    
    
}

int main()
{
    int NumOfCases;
    cin >> NumOfCases;
    
    for (int i = 0; i < NumOfCases; i++)
    {
        for (int m = 0; m < MAX_SIZE; m++)
        {
            for (int n = 0; n < MAX_SIZE; n++)
            {
                memo[m][n] = 0;
            }
        }

        cin >> a;
        cin >> b;

        cout << lcsR(0, 0) << '\n';
    }
}