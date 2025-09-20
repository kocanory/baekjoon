#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m, k;
vector<vector<int>> dist;
unordered_map<int, vector<pair<int, int>>> graph;

void dijkstra(int s) {
    dist[s][s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if (cost > dist[s][now]) continue;
        for (auto [next, ncost] : graph[now]) {
            ncost += cost;
            if (dist[s][next] > ncost) {
                dist[s][next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dist.assign(n + 1, vector(n + 1, (int)1e9));

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, 0});
        c ? graph[b].push_back({a, 0}) : graph[b].push_back({a, 1});
    }

    for (int i = 1;i <= n;i++) dijkstra(i);

    cin >> k;
    while (k--) {
        int s, e;
        cin >> s >> e;
        cout << dist[s][e] << "\n";
    }
    return 0;
}