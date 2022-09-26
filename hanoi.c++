#include <iostream>

using namespace std;

void hanoi(int n, int a, int b, int c);

int stack[9999];
int sp = 0;
int cntOfTree;

int main()
{
    int numOfCase;
    cin >> numOfCase;

    for (int i = 0; i < numOfCase; i++)
    {
        int numOfDisks;
        sp = 0;
        cntOfTree = 0;
        cin >> numOfDisks;
        hanoi(numOfDisks, 1, 2, 3);
        for (int i = 0; i < sp; i++)
        {
            cout << stack[i] << ' ';
            stack[i] = 0;
        }
        cout << '\n';
    }
}

void hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        hanoi(n - 1, a, c, b);
        if (c == 3 && stack[sp] != n)
        {
            stack[sp] = n;
            sp++;
            cntOfTree++;
        }
        if (a == 3)
        {
            if (cntOfTree > 1)
            {
                int stop = 1, i;
                for (i = sp - 1; stop > 0 && i - 1 >= 0; i--)
                {
                    if (stack[i - 1] > stack[i])
                    {
                        stop--;
                    }
                    else if (stack[i - 1] < stack[i])
                    {
                        stop++;
                    }
                }
                stack[sp] = stack[i];
                sp++;
                cntOfTree--;
            }
            else
            {
                stack[sp] = 0;
                sp++;
                cntOfTree--;
            }
        }
        hanoi(n - 1, b, a, c);
    }
}