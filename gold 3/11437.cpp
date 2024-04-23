#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> parent, depth;
vector<bool> visited;
map<int, vector<int>> tree;

void checkDepth(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto next : tree[now]){
            if(visited[next]) continue;
            visited[next] = true;
            depth[next] = depth[now] + 1;
            parent[next] = now;
            q.push(next);
        }
    }
}

int LCA(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    
    while(depth[a] != depth[b]) b = parent[b];
    
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    parent.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    visited.assign(n + 1, false);
    
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    checkDepth();
    cin >> m;
    for(int i = 0;i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
    return 0;
}