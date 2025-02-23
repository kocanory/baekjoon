#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, d;
unordered_map<int, vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> pq;
vector<int> dist;

void dijkstra() {
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if (dist[now] < cost) continue;
        for (auto [next, n_cost] : graph[now]) {
            if (next > d) continue;
            n_cost += cost;
            if (n_cost < dist[next]) {
                dist[next] = n_cost;
                pq.push({-n_cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d;
    dist.assign(d + 1, 1e9);

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    for (int i = 0;i < d;i++)
        graph[i].push_back({i + 1, 1});

    dijkstra();

    cout << dist[d] << "\n";
    return 0;
}