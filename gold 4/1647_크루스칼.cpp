#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> parent;
priority_queue<tuple<int, int, int>> pq;

int findParent(int x){
    if(parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]);
}

void kruskal(){
    int sum = 0, maxCost = 0;
    while(!pq.empty()){
        auto[cost, x, y] = pq.top(); pq.pop();
        cost = -cost;
        
        int a = findParent(x), b = findParent(y);
        if(a != b){
            parent[b] = a;
            sum += cost;
            maxCost = max(maxCost, cost);
        }
    }
    cout << sum - maxCost << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    parent.assign(n + 1, 0);
    for(int i = 1;i <= n;i++) parent[i] = i;
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    kruskal();
    return 0;
}