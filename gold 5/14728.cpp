#include <iostream>
#include <vector>

using namespace std;

int N, T;
vector<int> t, s;
vector<vector<int>> dp(101, vector<int>(10001));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> T;
    t.assign(N + 1, 0);
    s.assign(N + 1, 0);
    
    for(int i = 1;i <= N;i++) cin >> t[i] >> s[i];
    
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= T;j++){
            if(j - t[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + s[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    cout << dp[N][T] << "\n";
    return 0;
}