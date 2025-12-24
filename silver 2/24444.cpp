#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n, m, r, a, b, c = 1;
vector<int> check;
map<int, set<int>> graph;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    check.assign(n + 1, 0);

    while (m--) {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    q.push(r);

    while (!q.empty()) {
        int now = q.front(); q.pop();
        check[now] = c++;

        for (int nxt : graph[now]) {
            if (!check[nxt]) {
                q.push(nxt);
                check[nxt] = 1;
            }
        }
    }

    for (int i = 1;i <= n;i++)
        cout << check[i] << "\n";

    return 0;
}