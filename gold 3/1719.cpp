#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

int n, m;
vector<vector<int>> dist, ans;
unordered_map<int, vector<tuple<int, int>>> graph;

void dijkstra(int start){
    priority_queue<tuple<int, int>> pq;
    pq.push({0, start});
    dist[start][start] = 0;
    
    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[start][now] < cost) continue;
        for(auto [next_node, next_cost] : graph[now]){
            next_cost += cost;
            if(dist[start][next_node] > next_cost){
                dist[start][next_node] = next_cost;
                pq.push({-next_cost, next_node});
                if(now == start) ans[start][next_node] = next_node;
                else ans[start][next_node] = ans[start][now];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(i == start) cout << "- ";
        else cout << ans[start][i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    dist.assign(n + 1, vector<int>(n + 1, 1e9));
    ans.assign(n + 1, vector<int>(n + 1));
    
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    for(int i = 1;i <= n;i++) dijkstra(i);
    return 0;
}