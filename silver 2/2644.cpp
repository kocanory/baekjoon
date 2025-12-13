#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, s, e, m, a, b;
map<int, vector<int>> graph;
vector<bool> check;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s >> e >> m;
    check.assign(n, false);

    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    q.push({s, 0});
    check[s] = true;

    while (!q.empty()) {
        auto [now, cnt] = q.front(); q.pop();
        if (now == e) {
            cout << cnt;
            exit(0);
        }
        for (int next : graph[now]) {
            if (!check[next]) {
                check[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }
    cout << -1;
    return 0;
}