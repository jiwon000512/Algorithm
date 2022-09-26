#include <iostream>

using namespace std;

int fibo(int n);

int main()
{
    int caseNum;
    cin >> caseNum;

    for (int i = 0; i < caseNum; i++)
    {
        int n;
        cin >> n;
        cout << fibo(n) << '\n';
    }
}

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}