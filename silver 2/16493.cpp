#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> arr;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(m + 1, {0, 0});
    dp.assign(m + 1, vector(n + 1, 0));

    for (int i = 1;i <= m;i++) {
        auto &[d, p] = arr[i];
        cin >> d >> p;
    }

    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            auto [d, p] = arr[i];
            if (d <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - d] + p);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[m][n];
    return 0;
}