#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c, ans;
vector<tuple<int, int, int>> arr;
vector<int> cost, parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) parent[max(x, y)] = min(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cost.assign(n + 1, 0);
    parent.assign(n + 1, 0);

    for (int i = 1;i <= n;i++) parent[i] = i;

    for (int i = 1;i <= n;i++) cin >> cost[i];
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> c;
            if (i == j) arr.push_back({cost[i], 0, i});
            else arr.push_back({c, i, j});
        }
    }

    sort(arr.begin(), arr.end());
    for (auto [c, u, v] : arr) {
        if (find(u) != find(v)) {
            join(u, v);
            ans += c;
        }
    }
    cout << ans;
    return 0;
}