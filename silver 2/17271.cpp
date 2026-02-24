#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dp.assign(n + 1, 0);
    dp[0] = 1;

    for (int i = 1;i <= n;i++) {
        if (i >= m) dp[i] = dp[i - 1] + dp[i - m];
        else dp[i] = dp[i - 1];
        dp[i] %= 1000000007;
    }
    cout << dp[n];
    return 0;
}