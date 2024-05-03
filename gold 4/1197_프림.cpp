#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int v, e, result = 0;
map<int, vector<tuple<int, int>>> node;
vector<bool> visited;

void solve(){
    visited.assign(v + 1, false);
    priority_queue<tuple<int, int>> pq;
    
    for(auto a : node[1]){
        auto[next, cost] = a;
        pq.push({-cost, next});
    }
    visited[1] = true;
    
    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        
        if(!visited[now]){
            visited[now] = true;
            result += cost;
            for(auto a : node[now]){
                auto[next, n_cost] = a;
                if(!visited[next]) pq.push({-n_cost, next});
            }
        }
    }
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e;
    for(int i = 0;i < e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }
    
    solve();
    return 0;
}