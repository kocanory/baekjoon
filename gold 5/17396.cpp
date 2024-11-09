#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <climits>

using namespace std;

int n, m;
vector<long long> sight, dist;
unordered_map<int, vector<tuple<int, int>>> route;

long long dijkstra(){
    priority_queue<tuple<long long, int>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while(!pq.empty()){
        auto [cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, next_cost] : route[now]){
            if(next != n - 1 && sight[next]) continue;
            if(dist[next] > (long long)next_cost + cost){
                dist[next] = (long long)next_cost + cost;
                pq.push({-((long long)next_cost + cost), next});
            }
        }
    }
    return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    sight.assign(n, 0);
    dist.assign(n + 1, LLONG_MAX);

    for(int i = 0;i < n;i++) cin >> sight[i];
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        route[a].push_back({b, c});
        route[b].push_back({a, c});
    }
    cout << dijkstra() << "\n";
    return 0;
}