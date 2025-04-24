#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 1, s = 0, e;
vector<int> vips, dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    vips.assign(m, 0);
    dp.assign(n + 1, 0);
    
    for(int i = 0;i < m;i++) cin >> vips[i];
    
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for(int i = 3;i <= n;i++) dp[i] = dp[i - 1] + dp[i - 2];
    
    for(int i = 0;i < m;i++){
        e = vips[i];
        ans *= dp[e - s - 1];
        s = e;
    }
    cout << ans * dp[n - s];
    return 0;
}