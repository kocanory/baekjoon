#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

int n, m, k, s, d, sum = 0;
unordered_map<int, vector<tuple<int, int>>> graph;
vector<int> increase;
vector<vector<int>> dist;

void dijkstra(){
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, s, 0});

    while(!pq.empty()){
        auto[cost, now, count] = pq.top(); pq.pop();
        cost = -cost;
        if(count >= n || dist[now][count] < cost) continue;
        for(auto [next, ncost] : graph[now]){
            ncost += cost;
            if(dist[next][count + 1] > ncost){
                dist[next][count + 1] = ncost;
                pq.push({-ncost, next, count + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> s >> d;
    dist.assign(n + 1, vector<int>(n + 1, 1e9));

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    increase.push_back(0);
    for(int i = 0;i < k;i++){
        int inc;
        cin >> inc;
        increase.push_back(inc);
    }
    dijkstra();
    for(auto &i : increase){
        int ans = 1e9;
        sum += i;
        for(int j = 0;j < n;j++)
            ans = min(ans, dist[d][j] + j * sum);
        cout << ans << "\n";
    }
    return 0;
}