#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<long long>> arr, dp; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, vector<long long>(n));
    dp.assign(n, vector<long long>(n));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
            
    dp[0][0] = 1;
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            if(arr[i][j] == 0) continue;
            if(i + arr[i][j] < n) dp[i + arr[i][j]][j] += dp[i][j];
            if(j + arr[i][j] < n) dp[i][j + arr[i][j]] += dp[i][j];
        }
    cout << dp[n - 1][n - 1];
    return 0;
}