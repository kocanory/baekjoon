#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m, r;
map<int, vector<int>> graph;
vector<int> ans, check;

void dfs(int now, int depth) {
    ans[now] = depth;
    check[now] = true;
    sort(graph[now].begin(), graph[now].end());
    for (int nxt : graph[now]) {
        if (!check[nxt])
            dfs(nxt, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    check.assign(n + 1, false);
    ans.assign(n + 1, -1);

    for (int i = 0, s, e;i < m;i++) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    dfs(r, 0);
    for (int i = 1;i <= n;i++)
        cout << ans[i] << "\n";
}