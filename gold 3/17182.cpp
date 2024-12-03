#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 1e9;
vector<vector<int>> dist;

void dfs(int now, int cnt, int visited, int sum){
    if(cnt == n){
        ans = min(ans, sum);
        return;
    }
    for(int i = 0;i < n;i++){
        if(visited & (1 << i)) continue;
        dfs(i, cnt + 1, visited | (1 << i), sum + dist[now][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    dist.assign(n, vector<int>(n));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> dist[i][j];
            
    for(int k = 0;k < n;k++)
        for(int i = 0;i <n;i++)
            for(int j = 0;j < n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    dfs(k, 1, 1 << k, 0);
    cout << ans << "\n";
    return 0;
}