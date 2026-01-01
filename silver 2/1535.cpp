#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> h, g;

void dfs(int idx, int heal, int sum) {
    ans = max(ans, sum);

    for (int i = idx;i < n;i++) {
        if (heal + h[i] < 100)
            dfs(i + 1, heal + h[i], sum + g[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    h.assign(n, 0);
    g = h;

    for (int i = 0;i < n;i++) cin >> h[i];
    for (int i = 0;i < n;i++) cin >> g[i];

    dfs(0, 0, 0);
    cout << ans;

    return 0;
}