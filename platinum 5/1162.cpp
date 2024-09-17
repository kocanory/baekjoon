#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <climits>

using namespace std;

int n, m, k;
long long ans = LLONG_MAX;
unordered_map<int, vector<tuple<int, long long>>> graph;
vector<vector<long long>> dist;

void dijkstra(){
    priority_queue<tuple<long long, int, int>> pq;
    pq.push({0, 1, 0});

    while(!pq.empty()){
        auto[cost, now, paved] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[paved][now] < cost) continue;
        for(auto [next, ncost] : graph[now]){
            ncost += cost;
            if(dist[paved][next] > ncost) {
                dist[paved][next] = ncost;
                pq.push({-ncost, next, paved});
            }
            if(paved < k && dist[paved + 1][next] > cost) {
                dist[paved + 1][next] = cost;
                pq.push({-cost, next, paved + 1});
            }
        }
    }
    for(int i = 0;i <= k;i++)
        ans = min(ans, dist[i][n]);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    dist.assign(k + 1, vector<long long>(n + 1, LLONG_MAX));
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dijkstra();
    return 0;
}