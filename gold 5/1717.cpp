#include <iostream>

using namespace std;

int parent[1000001];

int getParent(int i)
{
    if(parent[i] == i) return i;
    return parent[i] = getParent(parent[i]);
}

void Union(int x, int y)
{
    int a = getParent(x);
    int b = getParent(y);
    if(a > b) parent[a] = b;
    else parent[b] = a;
}

void check(int x, int y)
{
    if(getParent(x) == getParent(y))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i =0;i<=n;i++)
        parent[i] = i;
        
    for(int i = 0;i<m;i++)
    {
        int u, first, second;
        cin >> u >> first >> second;
        if(u == 0)
        {
            Union(first, second);
        }
        else
        {
            check(first, second);
        }
    }
    return 0;
}