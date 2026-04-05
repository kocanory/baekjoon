#include <iostream>
#include <vector>

using namespace std;

int n, m, mod = 1e9 + 7;
vector<vector<long long>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dp.assign(n + 1, vector(m + 1, 0ll));
    dp[0][0] = 1;

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % mod;

    cout << dp[n][m];
    return 0;
}