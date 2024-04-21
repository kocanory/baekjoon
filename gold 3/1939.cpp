#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>

using namespace std;

int n, m, s, e;
unordered_map<int, vector<tuple<int, int>>> graph;
vector<vector<bool>> visited;

bool bfs(int val){
    queue<int> q;
    q.push(s);
    visited.assign(n + 1, vector<bool>(n + 1));
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(now == e) return true;
        for(auto a : graph[now]){
            auto [next, cost] = a;
            if(!visited[now][next] && val <= cost){
                q.push(next);
                visited[now][next] = true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    cin >> s >> e;
    
    int low = 1, high = 1000000000;
    while(low <= high){
        int mid = (low + high) / 2;
        if(bfs(mid)) low = mid + 1;
        else high = mid - 1;
    }
    
    cout << high << "\n";
    return 0;
}