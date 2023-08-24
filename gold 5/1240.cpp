#include <iostream>

int dist[1001][1001];

using namespace std;

int main()
{
    for(int i = 1;i<=1000;i++)
    {
        for(int j = 1;j<=1000;j++)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n - 1;i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        dist[s][e] = d;
        dist[e][s] = d;
    }
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
    }
    }
    for(int i = 0;i<m;i++)
    {
        int s, e;
        cin >> s >> e;
        cout << dist[s][e] << endl;
    }
    return 0;
}