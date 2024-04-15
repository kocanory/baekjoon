#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int t, n, m, w;
vector<tuple<int, int, int>> edge;

bool check(){
    vector<int> dist(n + 1, 1e9);
    dist[0] = 1;
    
    for(int i = 1;i < n;i++){
        for(auto a : edge){
            auto[s, e, t] = a;
            dist[e] = min(dist[e], dist[s] + t);
        }
    }
    
    for(auto a : edge){
        auto[s, e, t] = a;
        if(dist[e] > dist[s] + t) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n >> m >> w;
        edge.clear();
        for(int i = 0;i < m;i++){
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({s, e, t});
            edge.push_back({e, s, t});
        }
        
        for(int i = 0;i < w;i++){
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({s, e, -t});
        }
        
        if(check()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}