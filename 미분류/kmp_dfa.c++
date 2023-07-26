#include <iostream>

using namespace std;

int DFA[3][1001];
char pt[1001], txt[1001];
int edge, cnt, ptSize, txtSize;

void constructDFA()
{
    int patLength = ptSize;
    DFA[pt[0]-'A'][0] = 1;
    int X = 0;

    for (int j = 1; j < patLength; j++)
    {
        for (int c = 0; c < 3; c++)
            DFA[c][j] = DFA[c][X];
        DFA[pt[j]-'A'][j] = j + 1;
        X = DFA[pt[j]-'A'][X];
    }

    for (int i = 0; i < 3; i++) {
		DFA[i][patLength] = DFA[i][X];
	}
    
}

void kmp()
{
    int i, j, txtLength, patLength;

    txtLength = txtSize;
    patLength = ptSize;

    for (int i = 0, j = 0; i < txtLength; i++)
    {
        j = DFA[txt[i]-'A'][j];
        if(j==patLength)
        {
            cnt++;
            //j = DFA[txt[i]-'A'][j];
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

        constructDFA();
        kmp();

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<=ptSize; j++)
            {
                if(DFA[i][j] != 0)
                    edge++;
                //cout << DFA[i][j] << ' ';
                DFA[i][j] = 0;
                //cout << DFA[i][j] << ' ';
            }
            //cout << '\n';
        }

        cout << edge << ' ' << cnt << '\n';
        
        cnt = 0;
        edge = 0;
        ptSize = 0;
        txtSize = 0;
    }
}