#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, {0, 0});
    dp.assign(n + 1, 0);

    for (auto &[a, b] : arr) cin >> a >> b;

    for (int i = 0;i < n;i++) {
        auto [d, v] = arr[i];
        if (i + d <= n) dp[i + d] = max(dp[i + d], dp[i] + v);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n];
    return 0;
}