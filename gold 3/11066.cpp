#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int t, k, a;
vector<int> sum;
vector<vector<int>> dp;

int calc(){
    for(int i = 1;i < k;i++){
        for(int j = 0;j < k - i;j++){
            int a = j, b = j + i;
            dp[a][b] = INT_MAX;
            for(int l = a;l < b;l++)
                dp[a][b] = min(dp[a][b], dp[a][l] + dp[l + 1][b] + sum[b + 1] - sum[a]);
        }
    }
    return dp[0][k - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> k;
        dp.assign(k, vector<int>(k, 0));
        sum.assign(k + 1, 0);
        for(int i = 0;i < k;i++)
        {
            cin >> a;
            sum[i + 1] = sum[i] + a;
        }
        cout << calc() << "\n";
    }
    return 0;
}