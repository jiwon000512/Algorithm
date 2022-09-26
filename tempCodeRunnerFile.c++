#include <iostream>

using namespace std;

void hanoi(int n, int a, int b, int c);

int stack[11];
int sp = 0;

int main()
{
    int numOfCase;
    cin >> numOfCase;

    for (int i = 0; i < numOfCase; i++)
    {
        int numOfDisks;
        cin >> numOfDisks;
        hanoi(numOfDisks, 1, 2, 3);
    }
}

void hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        hanoi(n - 1, a, c, b);
        cout << n << ": " << a << " -> " << c << '\n';
        hanoi(n - 1, b, a, c);
    }
}