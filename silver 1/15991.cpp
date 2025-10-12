#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<long long> dp(100001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 1, dp[2] = 2, dp[3] = 2, dp[4] = 3, dp[5] = 3, dp[6] = 6;
    for (int i = 7;i <= 100000;i++)
        dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}