#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m, r, s, e;
map<int, vector<int>> graph;
vector<int> ans, check;

void dfs(int now, int depth) {
    ans[now] = depth;
    check[now] = 1;
    sort(graph[now].begin(), graph[now].end(), greater<>());
    for (int nxt : graph[now]) {
        if (check[nxt] == -1)
            dfs(nxt, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    ans.assign(n + 1, -1);
    check = ans;

    while (m--) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    dfs(r, 0);
    for (int i = 1;i <= n;i++)
        cout << ans[i] << "\n";
}