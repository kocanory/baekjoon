#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, cnt;
unordered_map<int, vector<int>> up, down;
vector<bool> visited;

void dfs(unordered_map<int, vector<int>> &graph, int now){
    visited[now] = true;
    for(auto next : graph[now]){
        if(visited[next]) continue;
        cnt++;
        dfs(graph, next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0;i <m;i++){
        int a, b;
        cin >> a >> b;
        down[a].push_back(b);
        up[b].push_back(a);
    }
    
    for(int i = 1;i <= n;i++){
        cnt = 0;
        visited.assign(n + 1, false);
        dfs(up, i);
        visited.assign(n + 1, false);
        dfs(down, i);
        visited.assign(n + 1, false);
        cout << n - cnt - 1 << "\n";
    }

    return 0;
}