#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<string> arr;
vector<vector<int>> dp;

int chess(char color){
    dp.assign(n + 1, vector<int>(m + 1));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int val;
            if(!((i + j) % 2)) val = arr[i][j] != color;
            else val = arr[i][j] == color;
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + val;
        }
    }
    
    int result = 1e9;
    for(int i = 0;i <= n - k;i++)
        for(int j = 0;j <= m - k;j++)
            result = min(result, dp[i + k][j + k] - dp[i][j + k] - dp[i + k][j] + dp[i][j]);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    arr.assign(n, "");
    
    for(int i = 0;i <n;i++) cin >> arr[i];
    
    cout << min(chess('B'), chess('W')) << "\n";

    return 0;
}