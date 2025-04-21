#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m, Max = 0, cnt = 0, nodeNum;
vector<int> ans;
unordered_map<int, vector<int>> graph;

void bfs() {
    queue<int> q;
    q.push(1);
    ans[1] = 0;

    while (!q.empty()) {
        auto now = q.front(); q.pop();
        Max = max(Max, ans[now]);
        for (auto next : graph[now]) {
            if (ans[next] == -1) {
                ans[next] = ans[now] + 1;
                q.push(next);
            }
        }
    }
    for (int i = n;i >= 1;i--) {
        if (ans[i] == Max) {
            cnt++;
            nodeNum = i;
        }
    }
    cout << nodeNum << " " << Max << " " << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    ans.assign(n + 1, -1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs();
    return 0;
}