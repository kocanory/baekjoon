#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m, r, s, e;
long long cnt = 1, ans = 0;
map<int, vector<int>> graph;
vector<bool> check;

void dfs(int now, int depth) {
    check[now] = true;
    ans += cnt++ * depth;
    sort(graph[now].begin(), graph[now].end(), greater<>());

    for (int nxt : graph[now])
        if (!check[nxt])
            dfs(nxt, depth + 1);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    check.assign(n + 1, false);

    while (m--) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    dfs(r, 0);
    cout << ans;

    return 0;
}