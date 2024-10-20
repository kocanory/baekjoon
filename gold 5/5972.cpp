#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <queue>

using namespace std;

int n, m;
unordered_map<int, vector<tuple<int, int>>> graph;
vector<int> dist;

void dijkstra(){
    priority_queue<tuple<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, next_cost] : graph[now]){
            next_cost += cost;
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
    cout << dist[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dist.assign(n + 1, 1e9);

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dijkstra();
    return 0;
}