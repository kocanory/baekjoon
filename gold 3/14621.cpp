#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
vector<tuple<int, int, int>> graph;
vector<int> parent;
vector<char> gender;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y)
        parent[max(x, y)] = min(x, y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    gender.assign(n + 1, ' ');
    for (int i = 0;i <= n;i++) parent.push_back(i);
    for (int i = 1;i <= n;i++) cin >> gender[i];
    for (int i = 0;i < m;i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph.push_back({d, u, v});
    }
    sort(graph.begin(), graph.end());

    for (auto[d, u, v] : graph) {
        if (find(u) != find(v) && gender[u] != gender[v]) {
            join(u, v);
            ans += d;
        }
    }

    for (int i = 2;i <= n;i++)
        if (find(i) != find(i - 1)) {
            ans = -1;
            break;
        }
    cout << ans;
}