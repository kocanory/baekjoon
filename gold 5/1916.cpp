#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <queue>

using namespace std;

int n, m, s, e;
unordered_map<int, vector<tuple<int, int>>> graph;
vector<int> dist;

void dijkstra(){
    priority_queue<tuple<int, int>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto [d, now] = pq.top(); pq.pop();
        d = -d;
        if(dist[now] < d) continue;
        for(auto n : graph[now]){
            auto &[next, n_d] = n;
            if(dist[next] > (d + n_d)) {
                dist[next] = (d + n_d);
                pq.push({-(d + n_d), next});
            }
        }
    }
    cout << dist[e] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dist.assign(n + 1, 1e9);

    cin >> m;
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    cin >> s >> e;
    dijkstra();
    return 0;
}