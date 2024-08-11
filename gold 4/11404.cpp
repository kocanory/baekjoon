#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m;
unordered_map<int, vector<pair<int, int>>> graph;

void dijkstra(int start) {
    vector<int> dist(n, 1e9);
    dist[start] = 0;
    priority_queue<tuple<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto &n : graph[now]) {
            auto[next, next_cost] = n;
            if(cost + next_cost < dist[next]) {
                dist[next] = cost + next_cost;
                pq.push({-(cost + next_cost), next});
            }
        }
    }
    
    for(auto &d : dist)
        cout << (d != 1e9 ? d : 0) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cin >> m;
    for(int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
    }
    for(int i = 0;i < n;i++)
        dijkstra(i);
    return 0;
}