#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dp.assign(n + 1, 0);
    
    for(int i = 1;i <= n;i++){
        dp[i] = dp[i - 1] + 1;
        for(int j = 3;j < i;j++)
            dp[i] = max(dp[i], dp[i - j] * (j - 1));
    }
    cout << dp[n] << "\n";
    return 0;
}