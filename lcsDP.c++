#include <iostream>
using namespace std;

#define MAX_SIZE 101

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int L[MAX_SIZE][MAX_SIZE],S[MAX_SIZE][MAX_SIZE];
char s[MAX_SIZE];
char t[MAX_SIZE];

int lengthLCS(int m, int n)
{
    int i, j;
    for (i = 0; i <= m; i++)
        L[i][0] = 0;
    for (i = 0; i <= n; i++)
        L[0][i] = 0;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (s[i - 1] == t[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 0;
            }
            else
            {
            L[i][j] = MAX(L[i][j - 1], L[i - 1][j]);
            if(L[i][j] == L[i][j-1])
                S[i][j] = 1;
            else
                S[i][j] = 2;
    }
    return L[m][n];
}

void printLCS(int m, int n)
 {
     if(m==0 || n==0)
         return;
     if(S[m][n] == 0)
     {
         printLCS(m-1, n-1);
         printf("%c", s[m-1]);
     }   
     else if(S[m][n] == 1)
         printLCS(m, n-1);
     else if(S[m][n] == 2)
         printLCS(m-1, n);
}

int main()
{
    int NumOfCases;
    cin >> NumOfCases;
    
    for (int i = 0; i < NumOfCases; i++)
    {
        for (int m = 0; m < MAX_SIZE; m++)
        {
            for (int n = 0; n < MAX_SIZE; n++)
            {
                L[m][n] = 0;
            }
        }

        cin >> s;
        cin >> t;

        int sizeOfS = 0;
        int sizeOfT = 0;

        while(s[sizeOfS])
            sizeOfS++;
        while(t[sizeOfT])
            sizeOfT++;

        cout << lengthLCS(sizeOfS, sizeOfT) << ' ';
        printLCS(sizeOfS, sizeOfT);
        cout << '\n';
    }
}