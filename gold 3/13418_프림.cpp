#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, q, Min = 0, Max = 0;
unordered_map<int, vector<pair<int, int>>> graph;
vector<bool> check;
priority_queue<pair<int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;

    for (int i = 0;i <= q;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    check.assign(n + 1, false);
    check[0] = true;
    for (auto [nxt, cost] : graph[0]) {
        pq.push({-cost, nxt});
    }

    while (!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if (check[now]) continue;
        check[now] = true;
        if (!cost) Max++;
        for (auto [nxt, cost] : graph[now]) {
            if (!check[nxt])
                pq.push({-cost, nxt});
        }
    }

    check.assign(n + 1, false);
    check[0] = true;
    for (auto [nxt, cost] : graph[0]) {
        pq.push({cost, nxt});
    }

    while (!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        if (check[now]) continue;
        check[now] = true;
        if (!cost) Min++;
        for (auto [nxt, cost] : graph[now]) {
            if (!check[nxt])
                pq.push({cost, nxt});
        }
    }

    cout << Max * Max - Min * Min;
    return 0;
}