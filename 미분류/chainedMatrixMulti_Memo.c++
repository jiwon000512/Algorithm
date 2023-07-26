#include <iostream>

using namespace std;

#define MAX_SIZE 101

int memo[MAX_SIZE][MAX_SIZE];

int cmm(int a[], int i, int j)
{
    if(i==j)
        return 0;
    
    if(memo[i][j] != -1)
    {
        return  memo[i][j];
    }
    else
    {
        for (int k = i; k < j; k++)
        {
            int tmp = cmm(a, i, k) + cmm(a, k + 1, j) + a[i - 1] * a[k] * a[j];
            if(memo[i][j] == -1 || memo[i][j] > tmp)
            {
                memo[i][j] = tmp;
            }
        }
        return memo[i][j];
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
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

        for(int m = 0; m<=n; m++)
        {
            for(int k=0; k<=n; k++)
            {
                if(m==k)
                {
                    memo[m][k] = 0;
                }
                else
                {
                    memo[m][k] = -1;
                }
            }
        }

        cout << cmm(a, 1, n) << '\n';
    }
}