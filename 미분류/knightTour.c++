#include <iostream>

using namespace std;

#define MAXSIZE 9

#define MARK 1
#define UNMARK 0

struct Point
{
    int x;
    int y;
};

Point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

bool knightTour(int x, int y, Point p, int counter)
{
    Point next;
    if (counter == x * y)
        return 1;

    for (int i = 7; i >= 0; i--)
    {
        next.x = p.x + direction[i].x;
        next.y = p.y + direction[i].y;

        if (next.x <= 0 || next.y <= 0 || next.x > x || next.y > y || board[next.x][next.y] == MARK)
        {
        }
        else
        {
            board[next.x][next.y] = MARK;
            path[next.x][next.y] = counter + 1;
            if (knightTour(x, y, next, counter + 1) == 0)
            {
                board[next.x][next.y] = UNMARK;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

void printTour(int x, int y)
{
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int x, y;
        Point start;

        cin >> x >> y >> start.x >> start.y;

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                board[i][j] = UNMARK;
            }
        }

        board[start.x][start.y] = MARK;
        path[start.x][start.y] = 1;

        if (knightTour(x, y, start, 1) == 1)
        {
            cout << 1 << '\n';
            printTour(x, y);
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}