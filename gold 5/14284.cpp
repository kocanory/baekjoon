#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m, s, t;
unordered_map<int, vector<pair<int, int>>> graph;
vector<vector<int>> dist;
priority_queue<pair<int, int>> pq;

void dijkstra() {
    pq.push({0, s});

    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if (dist[s][now] < cost) continue;
        for (auto [next, n_cost] : graph[now]) {
            n_cost += cost;
            if (n_cost < dist[s][next]) {
                dist[s][next] = n_cost;
                pq.push({-n_cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dist.assign(n + 1, vector<int>(n + 1, 1e9));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> s >> t;
    dijkstra();
    cout << dist[s][t] << "\n";
    return 0;
}