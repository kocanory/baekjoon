#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int v, e, result = 0;
priority_queue<tuple<int, int, int>> pq;
vector<int> parent;

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void solve(){
    while(!pq.empty()){
        auto[cost, p, c] = pq.top(); pq.pop();
        cost = -cost;
        int a = find(p), b = find(c);
        if(a != b){
            result += cost;
            parent[b] = a;
        }
    }
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e;
    parent.assign(v + 1, 0);
    for(int i = 1;i <= v;i++) parent[i] = i;
    
    for(int i = 0;i < e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    solve();
    return 0;
}