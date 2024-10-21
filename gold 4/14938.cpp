#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <queue>

using namespace std;

int n, m, r, ans = 0;
unordered_map<int, vector<tuple<int, int>>> graph;
vector<int> dist, item;

int dijkstra(int start){
    int sum = 0;
    priority_queue<tuple<int, int>> pq;
    pq.push({0, start});
    dist.assign(n + 1, 1e9);
    dist[start] = 0;

    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, next_cost] : graph[now]){
            next_cost += cost;
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }

    for(int i = 1;i <= n;i++)
        if(dist[i] <= m)
            sum += item[i];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    item.assign(n + 1, 0);

    for(int i = 1;i <= n;i++) cin >> item[i];

    for(int i = 0;i < r;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(int i = 1;i <= n;i++)
        ans = max(ans, dijkstra(i));
    cout << ans << "\n";
    return 0;
}