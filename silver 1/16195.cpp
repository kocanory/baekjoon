#include <iostream>
#include <vector>

using namespace std;

int t, n, m, mod = 1e9 + 9;
long long dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1][1] = dp[2][1] = dp[3][1] = 1;

    for (int i = 2;i <= 1000;i++)
        for (int j = 1;j <= 1000;j++)
            for(int k = 1;k <= 3;k++){
                if(j - k > 0){
                    dp[j][i] += dp[j - k][i - 1];
                    dp[j][i] %= mod;
                }
            }

    cin >> t;
    while(t--){
        cin >> n >> m;
        long long ans = 0;
        for(int i = 1;i <= m;i++){
            ans += dp[n][i];
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}