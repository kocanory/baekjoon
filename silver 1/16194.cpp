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
    dp = vector<int>(n + 1);
    
    for(int i = 1;i <= n;i++) cin >> dp[i];
    
    for(int i = 2;i <= n;i++)
        for(int j = 1;j <= i;j++)
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
    
    cout << dp[n];
    return 0;
}