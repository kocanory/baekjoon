#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<vector<long long>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector<long long>(21));
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    dp[0][arr[0]] = 1;
    for(int i = 1;i <= n - 2;i++){
        for(int j = 0;j <= 20;j++){
            if(dp[i - 1][j]){
                if(j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
                if(j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
            }
        }
    }
    cout << dp[n - 2][arr[n - 1]] << "\n";
    return 0;
}