#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<long long> dp(1000001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4;i <= 1000000;i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % ((int)1e9 + 9);

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}