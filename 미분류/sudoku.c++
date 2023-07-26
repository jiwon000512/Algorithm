#include <iostream>

using namespace std;

#define n 4

int board[n][n];
bool alreadyPrinted = false;

bool check(int x, int y, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (board[x][i] == target)
        {
            return false;
        }
        if (board[i][y] == target)
        {
            return false;
        }
    }

    int X = (x/2)*2;
    int Y = (y/2)*2;

    for (int i = X; i < X + 2; i++)
    {
        for (int j = Y; j < Y + 2; j++)
        {
            if (board[i][j] == target)
                return false;
        }
    }
    return true;
}

void printSudoku()
{
    for (int j = 0; j < n; j++)
    {
        cout << board[j][0] << ' ' << board[j][1] << ' ' << board[j][2] << ' ' << board[j][3] << '\n';
    }
}

void sudoku(int x, int y)
{
    if (y == n)
    {
        x++;
        y = 0;
    }

    if (x == n)
    {
        if(!alreadyPrinted)
        {
            printSudoku();
            alreadyPrinted = true;
        }
        return;
        
    }

    if (board[x][y] != 0)
    {
        sudoku(x, y + 1);
        return;
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (check(x, y, i))
        {
            board[x][y] = i;
            sudoku(x, y + 1);
            //board[x][y] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[j][0] >> board[j][1] >>
                board[j][2] >> board[j][3];
        }

        sudoku(0, 0);

        alreadyPrinted = false;
    }
}
