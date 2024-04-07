#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int n, m, s, e;
vector<vector<tuple<int, int>>> graph;
vector<int> d, trace, route;

void dijkstra(){
    d[s] = 0;
    priority_queue<tuple<int, int>> pq;
    pq.push({s, 0});
    
    while(!pq.empty()){
        auto[cur, dist] = pq.top(); pq.pop();
        dist = -dist;
        if(d[cur] < dist) continue;
        for(auto n : graph[cur]){
            auto[next, nextDist] = n;
            nextDist += dist;
            if(nextDist < d[next]){
                d[next] = nextDist;
                pq.push({next, -nextDist});
                trace[next] = cur;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    graph.assign(n + 1, vector<tuple<int, int>>());
    d.assign(n + 1, 1e9);
    trace.assign(n + 1, 1e9);
    
    for(int i = 0;i < m;i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        graph[x].push_back({y, cost});
    }
    
    cin >> s >> e;
    dijkstra();
    
    cout << d[e] << "\n";
    route.push_back(e);
    for(int i = e;i != s;){
        route.push_back(trace[i]);
        i = trace[i];
    }
    
    cout << route.size() << "\n";
    for(int i = route.size() - 1;i >= 0;i--)
        cout << route[i] << " ";
    return 0;
}