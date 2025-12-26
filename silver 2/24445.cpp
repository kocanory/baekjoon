#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, r, a, b, c = 1;
map<int, vector<int>> graph;
vector<int> ans;
queue<int> q;

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

    q.push(r);

    while (!q.empty()) {
        int now = q.front(); q.pop();
        ans[now] = c++;

        sort(graph[now].begin(), graph[now].end(), greater<>());
        for (int nxt : graph[now]) 
            if (!ans[nxt]) {
                ans[nxt] = 1;
                q.push(nxt);
            }
    }

    for (int i = 1;i <= n;i++)
        cout << ans[i] << "\n";

    return 0;
}