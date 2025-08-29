#include <iostream>
#include <vector>

using namespace std;

int n;
long long mod = 987654321;
vector<long long> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp = vector(n + 1, 0ll);

    dp[0] = 1, dp[2] = 1;
    for (int i = 4;i <= n;i += 2) {
        for (int j = 0;j < i / 2;j += 2) {
            if (j != i - j - 2)
                dp[i] += dp[j] * dp[i - j - 2] * 2 % mod;
            else
                dp[i] += dp[j] * dp[i - j - 2] % mod;
        }
        dp[i] %= mod;
    }
    cout << dp[n];
    return 0;
}