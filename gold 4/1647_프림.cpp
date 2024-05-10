#include <iostream>
#include <unordered_map>
#include <tuple>
#include <queue>

using namespace std;

int n, m;
unordered_map<int, vector<tuple<int, int>>> route;
vector<bool> visited;

void prim(){
    priority_queue<tuple<int, int>> pq;
    int maxCost = 0, sum = 0;
    visited[1] = true;
    for(auto &a : route[1]){
        auto [next, cost] = a;
        pq.push({-cost, next});
    }
    
    while(!pq.empty()){
        auto [cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(!visited[now]){
            visited[now] = true;
            maxCost = max(cost, maxCost);
            sum += (cost);
            for(auto &a : route[now]){
                auto [next, n_cost] = a;
                pq.push({-n_cost, next});
            }
        }
    }
    cout << sum - maxCost << "\n";
}

int main()
{
    cin >> n >> m;
    visited.assign(n + 1, false);
    
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        route[a].push_back({b, c});
        route[b].push_back({a, c});
    }
    prim();
    return 0;
}