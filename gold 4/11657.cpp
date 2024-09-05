#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m;
vector<tuple<int, int, int>> edge;
vector<long long> dist;

void solve(){
    dist[1] = 0;
    for(int i = 1;i < n;i++)
        for(auto &e : edge){
            auto[from, to, cost] = e;
            if(dist[from] == 1e9) continue;
            if(dist[to] > dist[from] + cost)
                dist[to] = dist[from] + cost;
        }

    for(auto &e : edge){
        auto[from, to, cost] = e;
        if(dist[from] == 1e9) continue;
        if(dist[to] > dist[from] + cost){
            cout << -1 << "\n";
            return;
        }
    }
    for(int i = 2;i <= n;i++){
        if(dist[i] == 1e9) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dist.assign(n + 1, 1e9);

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }
    solve();
    return 0;
}