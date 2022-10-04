#include <iostream>

using namespace std;

int fastCompute(int x, int n);

int p(int x, int n);

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int x, n;
        cin >> x >> n;

        cout << fastCompute(x, n) << '\n';
    }
}

int fastCompute(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        return (fastCompute(x, n / 2) * fastCompute(x, n / 2)) % 1000;
    }
    else
    {
        return (x * fastCompute(x, (n - 1) / 2) * fastCompute(x, (n - 1) / 2)) % 1000;
    }
}