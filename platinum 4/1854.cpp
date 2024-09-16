#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

int n, m, k;
unordered_map<int, vector<tuple<int, int>>> graph;
unordered_map<int, priority_queue<int>> heap;

void dijkstra(){
    priority_queue<tuple<int, int>> pq;
    pq.push({0, 1});
    heap[1].push(0);
    
    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        for(auto [next, ncost] : graph[now]){
            ncost += cost;
            if(heap[next].size() < k){
                heap[next].push(ncost);
                pq.push({-ncost, next});
            }
            else{
                if(heap[next].top() > ncost){
                    heap[next].pop();
                    heap[next].push(ncost);
                    pq.push({-ncost, next});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    dijkstra();
    
    for(int i = 1;i <= n;i++){
        if(heap[i].size() < k) cout << "-1\n";
        else cout << heap[i].top() << "\n";
    }
    return 0;
}