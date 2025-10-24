#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l, t, s, e, ans = 1e9;
bool check[100001];
vector<int> route[100001], nodes[100001];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    for (int i = 1;i <= l;i++) {
        while (true) {
            cin >> t;
            if (t == -1) break;
            route[i].push_back(t);
            nodes[t].push_back(i);
        }
    }

    cin >> s >> e;
    for (auto a : nodes[s]) {
        q.push({a, 0});
        check[a] = true;
    }

    while (!q.empty()) {
        auto[now, cnt] = q.front(); q.pop();
        for (auto a : route[now]) {
            if (a == e) {
                ans = min(ans, cnt);
                break;
            }
            for (auto next : nodes[a]) {
                if (check[next]) continue;
                q.push({next, cnt + 1});
                check[next] = true;
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}