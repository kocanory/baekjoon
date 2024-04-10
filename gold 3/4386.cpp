#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
vector<tuple<double, double>> stars;
vector<int> parent;
priority_queue<tuple<double, int, int>> pq;
double result = 0.0;
int n;

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void solve(){
    for(int i = 0;i < n;i++){
        auto[x1, y1] = stars[i];
        for(int j = i + 1;j < n;j++){
            auto[x2, y2] = stars[j];
            double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            pq.push({-dist, i, j});
        }
    }
    
    parent.assign(n, 0);
    for(int i = 0;i < n;i++)
        parent[i] = i;
    
    while(!pq.empty()){
        auto[dist, i, j] = pq.top(); pq.pop();
        dist = -dist;
        int a = find(i), b = find(j);
        if(a != b){
            parent[b] = a;
            result += dist;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 0;i < n;i++){
        double x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }
    solve();
    cout.precision(3);
    cout << result << "\n";
    return 0;
}