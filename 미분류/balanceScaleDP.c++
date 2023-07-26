#include <iostream>

using namespace std;

#define TypeOfWeight 7
int weight[TypeOfWeight] = {100, 50, 20, 10, 5, 2, 1};
int main()
{
    int n, in, left = 0, right = 0;
    cin >> n >> left >> right;

    for (int i = 0; i < n - 2; i++)
    {
        cin >> in;
        if (left == right)
        {
            left += in;
        }
        else
        {
            left > right ? right += in : left += in;
        }
    }

    int gap = (left > right ? left - right : right - left);

    
}
