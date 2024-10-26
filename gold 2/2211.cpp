#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <queue>


using namespace std;

int n, m;
vector<int> dist, parent;
unordered_map<int, vector<tuple<int, int>>> graph;

void bfs(){
    priority_queue<tuple<int, int>> pq;
    pq.push({0, 1});
    dist.assign(n + 1, 1e9);
    parent.assign(n + 1, 1);
    dist[1] = 0;

    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, next_cost] : graph[now]){
            next_cost += cost;
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                parent[next] = now;
                pq.push({-next_cost, next});
            }
        }
    }
    cout << n - 1 << "\n";
    for(int i = 2;i <= n;i++)
        cout << i << " " << parent[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    bfs();
    return 0;
}

