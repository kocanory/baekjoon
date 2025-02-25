#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;

int n, m, k, idx;
ll Max = 0;
unordered_map<int, vector<pair<int, ll>>> graph;
vector<ll> dist, site;

void dijkstra(){
    priority_queue<pair<ll, int>> pq;
    for(auto s : site){
        pq.push({0, s});
        dist[s] = 0;
    }
    
    while(!pq.empty()){
        auto [cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, n_cost] : graph[now]){
            n_cost += cost;
            if(n_cost < dist[next]){
                dist[next] = n_cost;
                pq.push({-n_cost, next});
            }
        }
    }
    
    for(int i = 1;i <= n;i++){
        if(Max < dist[i]){
            Max = dist[i];
            idx = i;
        }
    }
    cout << idx << "\n" << Max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    dist.assign(n + 1, 1e12);
    site.assign(k, 0);
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        graph[b].push_back({a, c});
    }
    
    for(int i = 0;i < k;i++) cin >> site[i];
    dijkstra();
    
    return 0;
}