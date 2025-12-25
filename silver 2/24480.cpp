#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m, r, a, b, c = 1;
map<int, vector<int>> graph;
vector<int> ans;

void dfs(int now) {
    ans[now] = c++;

    sort(graph[now].begin(), graph[now].end(), greater<>());
    for (int nxt : graph[now])
        if (!ans[nxt])
            dfs(nxt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    ans.assign(n + 1, 0);

    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(r);

    for (int i = 1;i <= n;i++)
        cout << ans[i] << "\n";

    return 0;
}