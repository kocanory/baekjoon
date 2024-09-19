#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

int n, m, s, d;
unordered_map<int, vector<tuple<int, int>>> graph;
unordered_map<int, vector<int>> back;
vector<vector<bool>> check;

int dijkstra() {
    vector<int> dist(n + 1, 1e9);
    dist[s] = 0;

    priority_queue<tuple<int, int>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, ncost] : graph[now]) {
            if(check[now][next]) continue;
            ncost += cost;
            if(dist[next] == ncost) back[next].push_back(now);
            if(dist[next] > ncost) {
                back[next].clear();
                back[next].push_back(now);
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }
    return dist[d] == 1e9 ? -1 : dist[d];
}

void erase(int node) {
    for(auto &b : back[node]) {
        for(auto [next, cost] : graph[b]) {
            if(next == node && !check[b][next]) {
                check[b][next] = true;
                erase(b);
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> n >> m;
        if(!n && !m) break;

        cin >> s >> d;
        graph.clear();
        back.clear();
        check.assign(n + 1, vector<bool>(n + 1, false));

        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back(tuple(b, c));
        }

        dijkstra();
        erase(d);
        cout << dijkstra() << "\n";
    }

    return 0;
}