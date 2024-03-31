#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int t, k, n;
vector<int> sum;
vector<vector<int>> dp;

int calc(){
    for(int i = 0;i < k;i++){
        for(int j = 0;j < k - i;j++){
            int a = j, b = j + i;
            if(a == b) dp[a][b] = 0;
            else{
                for(int l = a;l < b;l++)
                    dp[a][b] = min(dp[a][b], dp[a][l] + dp[l + 1][b] + sum[b + 1] - sum[a]);
            }
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
        sum.assign(k + 1, 0);
        dp.assign(k, vector<int>(k, INT_MAX));
        
        for(int i = 0;i < k;i++){
            cin >> n;
            sum[i + 1] = sum[i] + n;
        }
        cout << calc() << "\n";
    }

    return 0;
}