#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m, v;
unordered_map<int, set<int>> route;
vector<bool> visited;

void dfs(int x){
    
    if(visited[x]) return;
    visited[x] = true;
    cout << x << " ";
    
    for(auto next : route[x])
        dfs(next);
}

void bfs(int x){
    queue<int> q;
    visited.assign(n + 1, false);
    q.push(x);
    visited[x] = true;
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        cout << now << " ";
        for(auto next : route[now]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> v;
    visited.assign(n + 1, false);
    for(int i = 0;i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        route[a].insert(b);
        route[b].insert(a);
    }
    
    dfs(v);
    cout << "\n";
    bfs(v);
    return 0;
}