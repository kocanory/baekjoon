#include <iostream>
#include <vector>

using namespace std;

int n, m, k, x, y, mid;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    dp.assign(n + 1, vector<int>(m +  1));
    x = (k - 1) / m + 1, y = (k - 1) % m + 1;

    dp[1][1] = 1;
    if (k == 0) {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
    }
    else {
        for (int i = 1;i <= x;i++)
            for (int j = 1;j <= y;j++)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];

        mid = dp[x][y];
        dp[x][y] = 1;

        for (int i = x;i <= n;i++)
            for (int j = y;j <= m;j++) {
                if (i == x && j == y) continue;
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }

        dp[n][m] *= mid;
    }
    cout << dp[n][m];
    return 0;
}