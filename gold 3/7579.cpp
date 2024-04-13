#include <iostream>
#include <vector>

using namespace std;

int n, m, sum = 0;
vector<int> b, cost;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    b.assign(101, 0);
    cost.assign(101, 0);
    dp.assign(101, vector<int>(10001));
    
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++){
        cin >> cost[i];
        sum += cost[i];
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= sum;j++){
            if(j - cost[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + b[i]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    
    for(int i = 0;i <= sum;i++)
        if(dp[n][i] >= m)
        {
            cout << i << "\n";
            break;
        }
    return 0;
}