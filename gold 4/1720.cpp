#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dp.assign(n + 1, 0);
    dp[0] = dp[1] = 1;
    
    for(int i = 2;i <= n;i++) dp[i] = dp[i - 1] + dp[i - 2] * 2;

    if (n % 2) cout << (dp[n] + dp[n / 2]) / 2;
    else cout << (dp[n] + dp[n / 2] + dp[n / 2 - 1] * 2) / 2;
    return 0;
}