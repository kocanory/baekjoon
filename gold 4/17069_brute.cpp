#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> arr;
vector<vector<vector<long long>>> dp;

void solve(){
    dp[0][0][1] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 1;j < n;j++){
            if(arr[i][j] == 1) continue;
            if(arr[i][j + 1] == 0) dp[0][i][j + 1] = dp[0][i][j] + dp[1][i][j];
            if(arr[i + 1][j] == 0) dp[2][i + 1][j] = dp[1][i][j] + dp[2][i][j];
            if(arr[i][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i + 1][j + 1] == 0)
                dp[1][i + 1][j + 1] = dp[0][i][j] + dp[1][i][j] + dp[2][i][j];
        }
    }
    cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1] << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n + 1, vector<int>(n + 1));
    dp.assign(3, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
            
    solve();
    return 0;
}