#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m, sum;
unordered_map<int, vector<tuple<int, int>>> graph;
vector<bool> visited;

void prim() {
    priority_queue<tuple<int, int>> pq;
    pq.push({0, 1});
    visited[1] = true;
    for(auto &n : graph[1]) {
        auto[nx, ncost] = n;
        pq.push({-ncost, nx});
    }
    while(!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(visited[now]) continue;
        visited[now] = true;
        sum += cost;
        for(auto &n : graph[now]) {
            auto[nx, ncost] = n;
            if(visited[nx]) continue;
            pq.push({-ncost, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    prim();
    cout << sum << "\n";
    return 0;
}