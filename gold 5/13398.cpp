#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int> arr;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector(2, 0));
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    ans = arr[0];
    
    for(int i = 1;i < n;i++){
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << "\n";
    return 0;
}