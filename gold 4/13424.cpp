#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int t, n, m, k, Min, ans;
unordered_map<int, vector<pair<int, int>>> graph;
vector<vector<int>> dist;
vector<int> friends;

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    dist[start][start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if (dist[start][now] < cost) continue;
        for (auto [next, n_cost] : graph[now]) {
            n_cost += cost;
            if (n_cost < dist[start][next]) {
                dist[start][next] = n_cost;
                pq.push({-n_cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        graph.clear();

        cin >> n >> m;
        dist.assign(n + 1, vector<int>(n + 1, 1e9));

        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        cin >> k;
        friends.assign(k, 0);
        for (int i = 0;i < k;i++) {
            cin >> friends[i];
            dijkstra(friends[i]);
        }

        Min = 1e9;
        for (int i = 1;i <= n;i++) {
            int sum = 0;
            for (auto f : friends)
                sum += dist[f][i];
            if (sum < Min) {
                Min = sum;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}