#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj, dist;
vector<int> maxTimelist, visited;

int dfs(int now){
    visited[now] = true;
    int leader = now;
    for(int next = 1;next <= n;next++){
        if(!adj[now][next] || visited[next]) continue;
        int cand = dfs(next);
        if(maxTimelist[leader] > maxTimelist[cand]) leader = cand;
    }
    return leader;
}

vector<int> findLeaders(){
    vector<int> leaders;
    for(int i = 1;i <= n;i++){
        if(!visited[i]) leaders.push_back(dfs(i));
    }
    return leaders;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    adj.assign(n + 1, vector<int>(n + 1));
    dist.assign(n + 1, vector<int>(n + 1));
    maxTimelist.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = 1;
            else dist[i][j] = 1e9;
        }
    }
    
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                
    for(int i = 1;i <= n;i++){
        int maxTime = -1;
        for(int j = 1;j <= n;j++){
            if(dist[i][j] == 1e9) continue;
            maxTime = max(maxTime, dist[i][j]);
        }
        maxTimelist[i] = maxTime;
    }
    
    vector<int> leaders = findLeaders();
    sort(leaders.begin(), leaders.end());
    cout << leaders.size() << "\n";
    for(auto &l : leaders) cout << l << "\n";
    return 0;
}