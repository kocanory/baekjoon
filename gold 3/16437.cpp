#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

int n;
unordered_map<int, vector<int>> tree;
vector<ll> cnt;

ll dfs(int p, int now) {
    ll sum = cnt[now];
    for (int next : tree[now])
        if (next != p)
            sum += dfs(now, next);
    return sum > 0 ? sum : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cnt.assign(n + 1, 0);
    for (int i = 2;i <= n;i++) {
        char t; int a, p;
        cin >> t >> a >> p;
        a = t == 'W' ? -a : a;
        tree[i].push_back(p);
        tree[p].push_back(i);
        cnt[i] += a;
    }
    cout << dfs(-1, 1);
    return 0;
}