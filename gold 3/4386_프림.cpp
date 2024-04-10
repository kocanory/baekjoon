#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;

int n;
double result = 0;
vector<tuple<double, double>> stars;
vector<bool> visited;
unordered_map<int, vector<tuple<int, double>>> node;

void solve(){
    for(int i = 0;i < n;i++){
        auto[x1, y1] = stars[i];
        for(int j = i + 1;j < n;j++){
            auto[x2, y2] = stars[j];
            double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            node[i].push_back({j, dist});
            node[j].push_back({i, dist});
        }
    }
    
    visited.assign(n, false);
    priority_queue<tuple<double, int>> pq;
    
    for(auto a : node[0]){
        auto[next, dist] = a;
        pq.push({-dist, next});
    }
    visited[0] = true;
    
    while(!pq.empty()){
        auto[dist, now] = pq.top(); pq.pop();
        dist = -dist;
        
        if(!visited[now]){
            result += dist;
            visited[now] = true;
            for(auto a : node[now]){
                auto[next, dist] = a;
                if(!visited[next]) pq.push({-dist, next});
            }
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