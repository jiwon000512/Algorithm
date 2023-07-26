#include <iostream>

using namespace std;

#define MAX_SIZE 100

int pt[MAX_SIZE];
int sz[MAX_SIZE];

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        pt[i] = i;
        sz[i] = 1;
    }
}

int find(int x)
{
    int parent;
    int root = x;
    while(pt[root] != root)
        root = pt[root];
    
    while(pt[x] != root)
    {
        parent = pt[x];
        pt[x] = root;
        x = parent;
    }

    /*
    while(pt[i] != x)
    {
        id[x]
    }
    */

    return root;
}

bool in_same_set(int p, int q)
{
    return find(p) == find(q);
}

void _union(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if(i!=j)
        if(sz[i] < sz[j]){pt[i] = j; sz[j] += sz[i];}
        else{pt[j] = i; sz[i] += sz[j];}
}

int main()
{

}