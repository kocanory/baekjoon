#include <iostream>

using namespace std;

int n, mod = 1000000;
int dp[2][3][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dp[0][0][1] = dp[0][1][1] = dp[1][0][1] = 1;
    
    for(int i = 2;i <= n;i++){
        dp[0][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1]) % mod;
        dp[0][1][i] = dp[0][0][i - 1] % mod;
        dp[0][2][i] = dp[0][1][i - 1] % mod;
        dp[1][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1] + dp[1][0][i - 1] + dp[1][1][i - 1] + dp[1][2][i - 1]) % mod;
        dp[1][1][i] = dp[1][0][i - 1] % mod;
        dp[1][2][i] = dp[1][1][i - 1] % mod;
    }
    cout << (dp[0][0][n] + dp[0][1][n] + dp[0][2][n] + dp[1][0][n] + dp[1][1][n] + dp[1][2][n]) % mod;
    return 0;
}