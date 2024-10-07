#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> sum;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    sum.assign(n + 1, 0);
    dp.assign(4, vector<int>(n + 1));
    
    for(int i = 1;i <= n;i++){
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    cin >> m;
    
    for(int i = 1;i <= 3;i++)
        for(int j = i * m;j <= n;j++)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + sum[j] - sum[j - m]);
    cout << dp[3][n] << "\n";
    return 0;
}