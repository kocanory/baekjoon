#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m, k, x;
vector<int> dist, ans;
unordered_map<int, vector<int>> graph;
priority_queue<pair<int, int>> pq;

void dijkstra(){
    dist[x] = 0;
    pq.push({0, x});
    
    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto next : graph[now]){
            if(cost + 1 < dist[next]){
                dist[next] = cost + 1;
                pq.push({-(cost + 1), next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k >> x;
    dist.assign(n + 1, 1e9);
    
    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    dijkstra();
    
    for(int i = 1;i <= n;i++)
        if(dist[i] == k)
            ans.push_back(i);
    
    if(ans.empty()) cout << -1 << "\n";
    else{
        for(auto a : ans)
            cout << a << "\n";
    }
    return 0;
}