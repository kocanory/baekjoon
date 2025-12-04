#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, k, m, d;
string b;
queue<int> q;
vector<int> check;
unordered_map<int, int> bit;
unordered_map<int, vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    check.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> b;
        int t = 1, num = 0;
        for (int j = k - 1;j >= 0;j--, t *= 2) {
            num += (b[j] - '0') * t;
        }
        bit[num] = i;
    }

    for (auto [num, idx] : bit) {
        for (int i = 0;i < k;i++)
            if (bit.count(num ^ (1 << i)))
                graph[idx].push_back(bit[num ^ (1 << i)]);
    }

    q.push(1);
    check[1] = -1;

    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : graph[now]) {
            if (!check[next]) {
                q.push(next);
                check[next] = now;
            }
        }
    }

    cin >> m;
    while (m--) {
        cin >> d;
        if (!check[d]) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans;
        while (d != -1) {
            ans.push_back(d);
            d = check[d];
        }
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}