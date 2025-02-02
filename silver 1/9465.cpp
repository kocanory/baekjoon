#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<vector<int>> arr, dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(2, vector<int>(n));
        dp.assign(2, vector<int>(n));
        
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < n;j++)
                cin >> arr[i][j];
                
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];
        
        for(int i = 2;i < n;i++){
            dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }

    return 0;
}