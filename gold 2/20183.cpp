#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

int n, m, a, b;
ll c;
unordered_map<int, vector<pair<int, ll>>> graph;
priority_queue<tuple<ll, ll, int>> pq;
vector<ll> dist;

void dijkstra() {
    pq.push({0, 0, a});
    dist[a] = 0;

    while (!pq.empty()) {
        auto[Max, cost, now] = pq.top(); pq.pop();
        Max = -Max;
        if (dist[now] < Max) continue;
        for (auto [next, n_cost] : graph[now]) {
            ll n_max = max(Max, n_cost);
            n_cost += cost;
            if (n_cost > c) continue;
            if (n_max < dist[next]) {
                dist[next] = n_max;
                pq.push({-n_max, n_cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> a >> b >> c;
    dist.assign(n + 1, 1e15);

    while (m--) {
        int f, t;
        ll d;
        cin >> f >> t >> d;
        graph[f].push_back({t, d});
        graph[t].push_back({f, d});
    }

    dijkstra();
    cout << (dist[b] == 1e15 ? -1 : dist[b]) << "\n";
    return 0;
}