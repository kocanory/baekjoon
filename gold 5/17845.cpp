#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, int>> arr;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    arr.assign(k + 1, {0, 0});
    dp.assign(k + 1, vector<int>(n + 1, 0));
    
    for(int i = 1;i <= k;i++) cin >> arr[i].first >> arr[i].second;
    
    for(int i = 1;i <= k;i++)
        for(int j = 1;j <= n;j++){
            if(arr[i].second > j) dp[i][j] = dp[i - 1][j]; 
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].second] + arr[i].first);
        }
    cout << dp[k][n];
    return 0;
}