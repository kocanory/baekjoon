#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int n, answer = 0;
unordered_map<int, vector<tuple<int, int>>> info;
vector<tuple<int, int>> x, y, z;
vector<bool> visited;

void prim(){
    priority_queue<tuple<int, int>> pq;
    visited[0] = true;

    for(auto &n : info[0]){
        auto[n_cost, next] = n;
        pq.push({-n_cost, next});
    }

    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        answer += (-cost);
        for(auto &n : info[now]){
            auto[n_cost, next] = n;
            pq.push({-n_cost, next});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    visited.assign(n, false);
    for(int i = 0;i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i = 0;i < n - 1;i++){
        info[get<1>(x[i + 1])].push_back({get<0>(x[i + 1]) - get<0>(x[i]), get<1>(x[i])});
        info[get<1>(x[i])].push_back({get<0>(x[i + 1]) - get<0>(x[i]), get<1>(x[i + 1])});
        info[get<1>(y[i + 1])].push_back({get<0>(y[i + 1]) - get<0>(y[i]), get<1>(y[i])});
        info[get<1>(y[i])].push_back({get<0>(y[i + 1]) - get<0>(y[i]), get<1>(y[i + 1])});
        info[get<1>(z[i + 1])].push_back({get<0>(z[i + 1]) - get<0>(z[i]), get<1>(z[i])});
        info[get<1>(z[i])].push_back({get<0>(z[i + 1]) - get<0>(z[i]), get<1>(z[i + 1])});
    }
    prim();
    cout << answer << "\n";
    return 0;
}