#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, total = 0, sum = 0, cnt = 0;
unordered_map<int, vector<pair<int, int>>> graph;
vector<bool> check;
priority_queue<pair<int, int>> pq;

int conv(char c) {
    if (isupper(c))
        return c - 'A' + 27;
    return c - 'a' + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    check.assign(n, false);

    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        for (int j = 0;j < n;j++) {
            if (s[j] == '0') continue;
            total += conv(s[j]);
            if (i == j) continue;
            graph[i].push_back({j, conv(s[j])});
            graph[j].push_back({i, conv(s[j])});
        }
    }

    for (int i = 0;i < n;i++) {
        if (!graph[i].empty()) {
            for (auto [next, cost] : graph[i])
                pq.push({-cost, next});
            check[i] = true;
            break;
        }
    }

    while (!pq.empty()) {
        auto[cost, now] = pq.top(); pq.pop();
        cost = -cost;
        if (check[now]) continue;
        check[now] = true;
        sum += cost;
        cnt++;
        for (auto [next, nextCost] : graph[now]) {
            if (!check[next])
                pq.push({-nextCost, next});
        }
    }

    if (cnt < n - 1) cout << -1;
    else cout << total - sum;
    return 0;
}