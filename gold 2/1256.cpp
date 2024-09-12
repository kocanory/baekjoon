#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int dp[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1;i <= 100;i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for(int i = 1;i <= 100;i++){
        for(int j = 1;j <= 100;j++){
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] = min(1000000000, dp[i][j]);
        }
    }

    if(dp[n][m] < k){
        cout << -1 << "\n";
        return 0;
    }

    int a_cnt = n, z_cnt = m;
    for(int i = 0;i < n + m;i++){
        int ans = dp[a_cnt][z_cnt];
        if(!a_cnt){
            cout << 'z';
            z_cnt--;
        }
        else if(!z_cnt){
            cout << 'a';
            a_cnt--;
        }
        else if(k <= ans){
            cout << 'a';
            a_cnt--;
        }
        else{
            k -= ans;
            cout << 'z';
            z_cnt--;
        }
    }
    return 0;
}