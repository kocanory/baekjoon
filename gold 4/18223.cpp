#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m, p;
unordered_map<int, vector<pair<int, int>>> graph;
vector<vector<int>> dist;
priority_queue<pair<int, int>> pq;

void dijkstra(int s){
    pq.push({0, s});
    dist[s][s] = 0;
    
    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[s][now] < cost) continue;
        for(auto [next, n_cost] : graph[now]){
            n_cost += cost;
            if(n_cost < dist[s][next]){
                dist[s][next] = n_cost;
                pq.push({-n_cost, next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> p;
    dist.assign(n + 1, vector<int>(n + 1, 1e9));
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    dijkstra(1);
    dijkstra(p);
    
    cout << (dist[1][n] >= dist[1][p] + dist[p][n] ? "SAVE HIM" : "GOOD BYE") << "\n";

    return 0;
}