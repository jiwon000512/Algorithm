#include <iostream>

using namespace std;

#define MAX_SIZE 101

int p[MAX_SIZE][MAX_SIZE];

int minmult(int n, int d[])
{
    int i, j, k, diagonal;
    long m[MAX_SIZE][MAX_SIZE];

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    int tmp;
    for (diagonal = 1; diagonal < n; diagonal++)
    {
        for (i = 1; i <= n - diagonal; i++)
        {
            j = i + diagonal;
            if(i==j)
            {
                continue;
            }
            m[i][j] = 9999999999;
            for (k = i; k < j; k++)
            {
                tmp = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if(tmp < m[i][j])
                {
                    m[i][j] = tmp;
                    p[i][j] = k;
                }
            }
        }
    }
    int re = m[1][n];
    return re;
}

void order(int i, int j)
{
    if(i==j)
        cout << "M" << i;
    else
    {
        int k = p[i][j];
        cout << "(";
        order(i,k);
        order(k+1,j);
        cout << ")";
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

        int result = minmult(n, a);
        order(1,n);
        cout << '\n';
        cout << result << '\n';
    }
}