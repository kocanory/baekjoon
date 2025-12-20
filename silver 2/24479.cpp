#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, m, r, a, b, c = 1;
vector<int> check;
map<int, set<int>> graph;

void dfs(int now) {
    check[now] = c++;

    for (int next : graph[now])
        if (!check[next])
            dfs(next);
}

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

    dfs(r);
    for (int i = 1;i <= n;i++) cout << check[i] << "\n";
    return 0;
}