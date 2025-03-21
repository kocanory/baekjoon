#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m, k, ans = 0;
unordered_map<int, vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> pq;
vector<bool> visited;

void prim(){
    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        cost = -cost;
        ans += cost;
        for(auto [next, n_cost] : graph[now]){
            if(visited[next]) continue;
            pq.push({-n_cost, next});
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    visited.assign(n + 1, false);
    
    for(int i = 0;i < k;i++){
        int num;
        cin >> num;
        pq.push({0, num});
    }

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    prim();
    return 0;
}