#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector dp(1001, -1);

int dfs(int now) {
    int &ret = dp[now];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = 0;i < now;i++)
        if ((now - i) % 2 == 0)
            ret += dfs((now - i) / 2);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0] = 0, dp[1] = 1;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dfs(n) << "\n";
    }
    return 0;
}