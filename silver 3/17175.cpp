#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> dp(51);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp[0] = 1, dp[1] = 1;

    for (int i = 2;i <= n;i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % int(1e9 + 7);

    cout << dp[n];
    return 0;
}