#include <iostream>
#include <vector>

using namespace std;

int n, cur;
vector<vector<int>> arr;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 2, vector<int>(2));
    dp.assign(n + 2, 0);

    for(int i = 1;i <= n;i++) cin >> arr[i][0] >> arr[i][1];
    for(int i = 1;i <= n + 1;i++) {
        cur = max(cur, dp[i]);
        if(i + arr[i][0] > n + 1) continue;
        dp[i + arr[i][0]] = max(dp[i + arr[i][0]], cur + arr[i][1]);
    }
    cout << cur << "\n";
    return 0;
}