#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, m, a, b, c;
map<int, vector<pair<int, int>>> graph;
vector<int> dist, dp;
priority_queue<pair<int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dist.assign(n + 1, 1e9);
    dp.assign(n + 1, 0);

    while(m--){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    pq.push({0, 2});
    dist[2] = 0, dp[2] = 1;

    while(!pq.empty()){
        auto [cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(cost > dist[now]) continue;
        for(auto [next, ncost] : graph[now]){
            ncost += cost;
            if(ncost < dist[next]){
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
            if(cost > dist[next])
                dp[now] += dp[next];
        }
    }
    cout << dp[1];
    return 0;
}