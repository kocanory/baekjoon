#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n;
unordered_map<int, vector<int>> tree;
bool cycle = false;
vector<bool> visited, check;

void dfs(int now, int start, int cnt) {
    if (now == start && cnt > 2) {
        cycle = true;
        check[now] = true;
        return;
    }

    visited[now] = true;
    for (auto next : tree[now]) {
        if (!visited[next] || (next == start && cnt >= 2)) dfs(next, start, cnt + 1);
        if (cycle) {
            check[now] = true;
            return;
        }
    }
}

int bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});

    visited = vector(n + 1, false);
    visited[start] = true;

    while (!q.empty()) {
        auto [now, cnt] = q.front(); q.pop();
        if (check[now]) return cnt;
        for (auto next : tree[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    visited = vector(n + 1, false);
    check = vector(n + 1, false);

    for (int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1;i <= n;i++) {
        if (check[i]) continue;

        visited = vector(n + 1, false);
        cycle = false;
        dfs(i, i, 0);
    }

    for (int i = 1;i <= n;i++) {
        if (check[i]) cout << 0 << " ";
        else cout << bfs(i) << " ";
    }
    return 0;
}