#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int v, e, k;
vector<vector<tuple<int, int>>> arr;
vector<int> d;

void dijkstra(){
    d[k] = 0;
    priority_queue<tuple<int, int>> pq;
    pq.push({0, k});
    
    while(!pq.empty()){
        auto[distance, now] = pq.top(); pq.pop();
        distance = -distance;
        
        if(d[now] < distance) continue;
        for(auto a : arr[now]){
            auto[next, cost] = a;
            cost += distance;
            if(cost < d[next]){
                d[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e;
    cin >> k;
    
    d.assign(v + 1, 1e9);
    arr.assign(v + 1, vector<tuple<int, int>>());
    
    for(int i = 0;i < e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }
    
    dijkstra();
    for(int i = 1;i <= v;i++){
        if(d[i] == 1e9) cout << "INF" << "\n";
        else cout << d[i] << "\n";
    }
    return 0;
}