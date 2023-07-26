#include <iostream>

using namespace std;

int two;

long long fac(int n);

int main()
{
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int n;
        two = 0;
        cin >> n;
        cout << fac(n) << '\n';
    }
}

long long fac(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 5 == 0)
    {
        int tmpN = n;
        while (tmpN % 5 == 0)
        {
            tmpN /= 5;
            two++;
        }
        while (tmpN % 2 == 0 && two > 0)
        {
            tmpN /= 2;
            two--;
        }
        return (tmpN * fac(n - 1)) % 1000;
    }
    else
    {
        int tmpN = n;
        while (tmpN % 2 == 0 && two > 0)
        {
            tmpN /= 2;
            two--;
        }
        return (tmpN * fac(n - 1)) % 1000;
    }
}