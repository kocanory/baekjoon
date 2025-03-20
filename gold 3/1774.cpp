#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int n, m;
double ans;
vector<int> parent;
vector<pair<int, int>> coord, connect;
vector<tuple<double, int, int>> edges;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}

double calcDist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve(){
    for(auto [x, y] : connect) join(x, y);
    for(int i = 0;i < n - 1;i++){
        auto [x1, y1] = coord[i];
        for(int j = i + 1;j < n;j++){
            auto [x2, y2] = coord[j];
            edges.push_back({calcDist(x1, y1, x2, y2), i + 1, j + 1});
        }
    }
    sort(edges.begin(), edges.end());
    for(auto [dist, x, y] : edges){
        if(find(x) != find(y)){
            join(x, y);
            ans += dist;
        }
    }
    cout << fixed << setprecision(2) << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    parent.assign(n + 1, 0);
    coord.assign(n, {0, 0});
    connect.assign(m, {0, 0});
    
    for(int i = 1;i <= n;i++) parent[i] = i;
    
    for(int i = 0;i < n;i++) cin >> coord[i].first >> coord[i].second;
    for(int i = 0;i < m;i++) cin >> connect[i].first >> connect[i].second;
    
    solve();
    return 0;
}