#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, m, a, b, ans = 0;
map<int, vector<int>> graph;
vector<bool> check;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    check.assign(n + 1, false);

    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    q.push({1, 0});
    check[1] = true;

    while (!q.empty()) {
        auto [now, cnt] = q.front(); q.pop();
        for (int nxt : graph[now]) 
            if (!check[nxt] && cnt <= 1) {
                q.push({nxt, cnt + 1});
                check[nxt] = true;
                ans++;
            }
    }
    cout << ans;
    return 0;
}