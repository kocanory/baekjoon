#include <iostream>
#include <vector>

using namespace std;

int n;
long long mod = 1000000007;
vector<vector<long long>> dp(1000001, vector<long long>(2));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dp[1][0] = 2;
    dp[2][0] = 7;
    dp[2][1] = 1;

    for(int i = 3;i <= n;i++){
        dp[i][1] = (dp[i - 3][0] + dp[i - 1][1]) % mod;
        dp[i][0] = (dp[i - 1][0] * 2 + dp[i - 2][0] * 3 + dp[i][1] * 2) % mod;
    }

    cout << dp[n][0] << "\n";
    return 0;
}