#include <iostream>
#include <vector>

using namespace std;

int n, num;
vector<vector<int>> dp(10001, vector<int>(4));

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    dp[1][1] = 1;
    
    dp[2][1] = 1;
    dp[2][2] = 1;
    
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    for(int i = 4;i <= 10000;i++){
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
    
    while(n--){
        cin >> num;
        cout << dp[num][1] + dp[num][2] + dp[num][3] << "\n";
    }
    return 0;
}