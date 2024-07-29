#include <iostream>

using namespace std;

int n;
int arr[16][16];
int dp[16][16][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
            
    dp[0][1][0] = 1;
    for(int i = 2;i < n;i++)
        if(!arr[0][i]) dp[0][i][0] = dp[0][i - 1][0];
        
    for(int i = 1;i < n;i++){
        for(int j = 2;j < n;j++){
            if(!arr[i][j]){
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
                dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
                if(!arr[i - 1][j] && !arr[i][j - 1])
                    dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }
    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << "\n";
    return 0;
}