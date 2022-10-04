#include <iostream>

using namespace std;

struct matrix p(struct matrix x, int n);

struct matrix multi(struct matrix a, struct matrix b);

struct matrix operator%(const struct matrix &a, int num);

struct matrix
{
    int arr[2][2];
};

struct matrix operator*(const struct matrix &a, const struct matrix &b);

int main()
{
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        int n;
        cin >> n;

        struct matrix a;
        a.arr[0][0] = 1;
        a.arr[0][1] = 1;
        a.arr[1][0] = 1;
        a.arr[1][1] = 0;

        cout << p(a, n).arr[1][0] << '\n';
    }
}

struct matrix p(struct matrix x, int n)
{
    struct matrix y;
    if (n == 0)
    {
        y.arr[0][0] = 1;
        y.arr[0][1] = 0;
        y.arr[1][0] = 0;
        y.arr[1][1] = 1;
        return y;
    }
    else if (n % 2 == 1)
    {
        y = p(x, (n - 1) / 2);
        return (x * (y * y)) % 1000;
    }
    else
    {
        y = p(x, n / 2);
        return (y * y) % 1000;
    }
}

struct matrix operator*(const struct matrix &a, const struct matrix &b)
{
    struct matrix re;
    re.arr[0][0] = 0;
    re.arr[0][1] = 0;
    re.arr[1][0] = 0;
    re.arr[1][1] = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                re.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }

    return re;
}

struct matrix operator%(const struct matrix &a, int num)
{
    struct matrix re;
    re.arr[0][0] = 0;
    re.arr[0][1] = 0;
    re.arr[1][0] = 0;
    re.arr[1][1] = 0;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            re.arr[i][j] = a.arr[i][j] % 1000;
        }
    }

    return re;
}