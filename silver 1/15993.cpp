#include <iostream>

using namespace std;

int t, n, mod = 1e9 + 9;
int dp[100001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1][0] = dp[2][0] = dp[2][1] = 1;
    dp[3][0] = dp[3][1] = 2;

    for (int i = 4;i <= 100000;i++)
        for (int j = 1;j <= 3;j++) {
            dp[i][0] += dp[i - j][1];
            dp[i][1] += dp[i - j][0];

            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << '\n';
    }
    return 0;
}