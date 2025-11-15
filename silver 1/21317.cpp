#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<int>> arr(20, {0, 0}), dp(21, {10000, 10000});

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1;i < n;i++) cin >> arr[i][0] >> arr[i][1];

    cin >> k;
    dp[1][0] = 0, dp[2][0] = arr[1][0], dp[3][0] = min(arr[1][0] + arr[2][0], arr[1][1]);

    for (int i = 4;i <= n;i++) {
        dp[i][0] = min(dp[i - 1][0] + arr[i - 1][0], dp[i - 2][0] + arr[i - 2][1]);
        dp[i][1] = min(min(dp[i - 1][1] + arr[i - 1][0], dp[i - 2][1] + arr[i - 2][1]), k + dp[i - 3][0]);
    }

    cout << min(dp[n][0], dp[n][1]);
    return 0;
}