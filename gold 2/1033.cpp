#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
typedef long long ll;

int n;
ll total_lcm = 1, ans_gcd;
vector<ll> ans;
unordered_map<int, vector<tuple<int, int, int>>> adj;
queue<int> qu;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ans.assign(n, 0);

    for (int i = 0;i < n - 1;i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        adj[a].push_back({b, p, q});
        adj[b].push_back({a, q, p});
        total_lcm *= lcm(p, q);
    }

    qu.push(0);
    ans[0] = total_lcm;
    while (!qu.empty()) {
        int now = qu.front(); qu.pop();
        for (auto [next, np, nq] : adj[now]) {
            if (ans[next]) continue;
            ans[next] = ans[now] * nq / np;
            qu.push(next);
        }
    }
    ans_gcd = ans[0];
    for (int i = 1;i < n;i++) ans_gcd = gcd(ans_gcd, ans[i]);
    for (auto a : ans) cout << a / ans_gcd << " ";
    return 0;
}