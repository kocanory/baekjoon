#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m, k, a, ans = -1;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> cost;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> m;
    for (int i = 1;i <= m;i++) {
        for (int j = 0;j < k;j++) {
            cin >> a;
            graph[a].push_back(i + n);
            graph[i + n].push_back(a);
        }
    }

    q.push(1);
    cost[1] = 1;

    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now == n) {
            ans = cost[now];
            break;
        }
        for (int next : graph[now]) {
            if (!cost[next]) {
                cost[next] = cost[now] + (next > n ? 0 : 1);
                q.push(next);
            }
        }
    }
    cout << ans;
    return 0;
}