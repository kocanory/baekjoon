#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int n, e, v1, v2, ans = 1e9;
unordered_map<int, vector<tuple<int, int>>> graph;
vector<int> dist;

void bfs(int start) {
    dist.assign(n + 1, 1e8);
    dist[start] = 0;
    priority_queue<tuple<int, int>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto &n : graph[now]) {
            auto[next, n_cost] = n;
            if(dist[next] > cost + n_cost) {
                dist[next] = cost + n_cost;
                pq.push({-(cost + n_cost), next});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    bfs(1);
    int to_v1 = dist[v1], to_v2 = dist[v2];

    bfs(v1);
    int v1_to_v2 = dist[v2], v1_to_n = dist[n];

    bfs(v2);
    int v2_to_n = dist[n];

    ans = min(ans, to_v1 + v1_to_v2 + v2_to_n);
    ans = min(ans, to_v2 + v1_to_v2 + v1_to_n);

    cout << (ans >= 1e8 ? -1 : ans) << endl;
    return 0;
}