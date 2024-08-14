#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int k, v, e;
vector<int> visited;
unordered_map<int, vector<int>> graph;

bool bfs(int i){
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto &next : graph[now]){
            if(!visited[next]){
                visited[next] = (visited[now] == 1 ? 2 : 1);
                q.push(next);
            }
            else{
                if(visited[next] == visited[now]) return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k;
    while(k--){
        cin >> v >> e;
        graph.clear();
        visited.assign(v + 1, 0);
        bool flag = true;
        
        for(int i = 0;i < e;i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i = 1;i <= v && flag;i++){
            if(!visited[i])
                flag = bfs(i);
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}