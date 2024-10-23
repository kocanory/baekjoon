#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <climits>

using namespace std;

int t, n, d, c, count, maxTime;
unordered_map<int, vector<tuple<int, int>>> dependancy;
vector<int> dist;

void dijkstra(int start){
    priority_queue<tuple<int, int>> pq;
    pq.push({0, start});
    dist.assign(n + 1, INT_MAX);
    dist[start] = 0;

    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, next_cost] : dependancy[now]){
            next_cost += cost;
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }

    for(int i = 1;i <= n;i++)
        if(dist[i] != INT_MAX){
            maxTime = max(maxTime, dist[i]);
            count++;
        }
    cout << count << " " << maxTime << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        count = 0;
        maxTime = 0;
        dependancy.clear();

        cin >> n >> d >> c;
        for(int i = 0;i < d;i++){
            int a, b, s;
            cin >> a >> b >> s;
            dependancy[b].push_back({a, s});
        }
        dijkstra(c);
    }
    return 0;
}