#include <iostream>

using namespace std;

int p(int x, int n);

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int x, n;
        cin >> x >> n;

        cout << p(x, n) << '\n';
    }
}

int p(int x, int n)
{
    int y;
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
    {
        y = p(x, (n - 1) / 2);
        return ((x * y * y) % 1000);
    }
    else
    {
        y = p(x, n / 2);
        return ((y * y) % 1000);
    }
}