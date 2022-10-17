#include <iostream>

using namespace std;

#define TypeOfWeight 7
int weight[TypeOfWeight] = {100, 50, 20, 10, 5, 2, 1};
int main()
{
    int numCases;
    cin >> numCases;
    while (numCases-- > 0)
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

        int ans = 0, gap = (left > right ? left - right : right - left);

        while (true)
        {
            for (int i = 0; i < TypeOfWeight; i++)
            {
                if (weight[i] <= gap)
                {
                    gap -= weight[i];
                    ans++;
                    break;
                }
            }

            if (gap == 0)
            {
                break;
            }
        }

        cout << ans << '\n';
    }
}