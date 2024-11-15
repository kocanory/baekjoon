#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int v, e, ans = INT_MAX;
unordered_map<int, vector<pair<int, int>>> map;
vector<vector<int>> dist;
priority_queue<pair<int, int>> pq;

int dikjstra(int s){
    pq.push({0, s});
    while(!pq.empty()){
        auto [cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[s][now] < cost) continue;
        for(auto [next, n_cost] : map[now]){
            n_cost += cost;
            if(dist[s][next] > n_cost){
                dist[s][next] = n_cost;
                pq.push({-n_cost, next});
            }
        }
    }
    return dist[s][s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v >> e;
    dist.assign(v + 1, vector<int>(v + 1, INT_MAX));

    for(int i = 0;i < e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b, c});
    }
    
    for(int i = 1;i <= v;i++) ans = min(ans, dikjstra(i));
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}