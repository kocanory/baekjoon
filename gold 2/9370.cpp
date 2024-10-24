#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

int T, n, m, t, s, g, h;
vector<int> distS, distG, distH, candidate;
unordered_map<int, vector<tuple<int, int>>> route;

void dijkstra(int start, vector<int> &dist){
    priority_queue<tuple<int, int>> pq;
    pq.push({0, start});
    dist.assign(n + 1, INT_MAX);
    dist[start] = 0;

    while(!pq.empty()){
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto [next, next_cost] : route[now]){
            next_cost += cost;
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> n >> m >> t;

        candidate.assign(t, 0);
        route.clear();

        cin >> s >> g >> h;

        for(int i = 0;i < m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            route[a].push_back({b, c});
            route[b].push_back({a, c});
        }

        dijkstra(s, distS);
        dijkstra(g, distG);
        dijkstra(h, distH);
        int GH = distG[h];

        for(int i = 0;i < t;i++) cin >> candidate[i];
        sort(candidate.begin(), candidate.end());

        for(auto &c : candidate){
            if(distS[c] == distS[g] + GH + distH[c]) cout << c << " ";
            else if(distS[c] == distS[h] + GH + distG[c]) cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}