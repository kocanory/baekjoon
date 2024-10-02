#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, order;
unordered_map<int, vector<int>> down, up;
vector<bool> visited;

void dfs(unordered_map<int, vector<int>> &graph, int now){
    visited[now] = true;
    for(auto &next : graph[now]){
        if(!visited[next]){
            order++;
            dfs(graph, next);
        }
    }
}

void solve(){
    int ans = 0;
    for(int i = 1;i <= n;i++){
        order = 0;
        visited.assign(n + 1, false);
        dfs(down, i);
        visited.assign(n + 1, false);
        dfs(up, i);
        if(order == n - 1) ans++;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        down[b].push_back(a);
        up[a].push_back(b);
    }
    solve();
    return 0;
}