#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int n, m, r;
map<int, vector<int>> graph;
vector<int> ans, check;

void bfs() {
    queue<pair<int, int>> q;
    q.push({r, 0});
    check[r] = true;

    while (!q.empty()) {
        auto[now, depth] = q.front(); q.pop();
        ans[now] = depth;
        sort(graph[now].begin(), graph[now].end());

        for (int nxt : graph[now]) {
            if (!check[nxt]) {
                check[nxt] = true;
                q.push({nxt, depth + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    ans.assign(n + 1, -1);
    check.assign(n + 1, false);

    for (int i = 0, s, e;i < m;i++) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    bfs();
    for (int i = 1;i <= n;i++)
        cout << ans[i] << "\n";
}