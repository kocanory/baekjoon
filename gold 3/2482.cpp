#include <iostream>

using namespace std;

int n, s, mod = 1000000003;
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    for(int i = 1;i <= n;i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    
    for(int i = 2;i <= n;i++)
        for(int j = 2;j <= s;j++)
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;

    cout << (dp[n - 1][s] + dp[n - 3][s - 1]) % mod << "\n";
    return 0;
}