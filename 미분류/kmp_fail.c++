#include <iostream>

using namespace std;

char pt[1001], txt[1001];
int fail[1001];
int cnt, ptSize, txtSize;

void getFail(string pt)
{
    int m = ptSize;
    int j = 0;

    for(int i=1; i<m; i++)
    {
        while(j > 0 && pt[i] != pt[j])
        {
            j = fail[j-1];
        }
        if(pt[i] == pt[j])
        {
            fail[i] = ++j;
        }
    }
}

void kmp(string txt, string pt)
{
    int n = txtSize, m = ptSize;
    int j = 0;

    for(int i=0; i<n; i++)
    {
        while(j > 0 && txt[i] != pt[j])
            j = fail[j-1];
        if(txt[i] == pt[j])
        {
            if(j == m-1)
            {
                cnt++;
                j = fail[j];
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for(int k=0; k<t; k++)
    {
        cin >> pt >> txt;
        
        while(pt[ptSize])
            ptSize++;
        while(txt[txtSize])
            txtSize++;

        getFail(pt);
        kmp(txt,pt);

        for(int i=0; i<ptSize; i++)
            cout << fail[i] << ' ';
        cout << '\n';
        cout << cnt << '\n';

        for(int i=0; i<ptSize; i++)
            fail[i] = 0;
        
        cnt = 0;
        ptSize = 0;
        txtSize = 0;
    }
}