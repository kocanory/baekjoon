#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m, k, ans = 0;
unordered_map<int, vector<pair<int, int>>> graph;
priority_queue<tuple<int, int, int>> pq;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[max(a, b)] = min(a, b);
}

void kruskal(){
    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        cost = -cost;
        if (find(x) == find(y)) continue;
        join(x, y);
        ans += cost;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    parent.assign(n + 1, 0);

    for (int i = 1;i <= n;i++) parent[i] = i;

    for (int i = 0; i < k;i++) {
        int num;
        cin >> num;
        parent[num] = 0;
    }

    for (int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    kruskal();
    return 0;
}