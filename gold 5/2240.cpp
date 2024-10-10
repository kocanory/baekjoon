#include <iostream>
#include <vector>

using namespace std;

int t, w, ans;
vector<int> arr;
int dp[31][2][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t >> w;
    arr.assign(t + 1, 0);

    for(int i = 1;i <= t;i++) cin >> arr[i];
    
    for(int j = 0;j <= w;j++){
        for(int i = 1;i <= t;i++){
            if(j == 0) dp[j][0][i] = dp[j][0][i - 1] + (arr[i] == 1);
            else{
                dp[j][0][i] = max(dp[j][0][i - 1] + (arr[i] == 1), dp[j - 1][1][i - 1] + (arr[i] == 1));
                dp[j][1][i] = max(dp[j][1][i - 1] + (arr[i] == 2), dp[j - 1][0][i - 1] + (arr[i] == 2));
            }
        }
    }
    for(int j = 0;j <= w;j++)
        for(int i = 0;i < 2;i++)
            ans = max(ans, dp[j][i][t]);
    cout << ans << "\n";
    return 0;
}