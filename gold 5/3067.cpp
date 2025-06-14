#include <iostream>
#include <vector>

using namespace std;

int t, n, m;
vector<int> coins, dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        coins.assign(n, 0);

        for(int i = 0;i < n;i++) cin >> coins[i];

        cin >> m;
        dp.assign(m + 1, 0);
        dp[0] = 1;

        for(auto c : coins)
            for(int i = 1;i <= m;i++)
                if(i >= c)
                    dp[i] += dp[i - c];
        cout << dp[m] << "\n";
    }
    return 0;
}