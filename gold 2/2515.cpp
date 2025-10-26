#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
vector<int> dp, limit;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    dp.assign(n + 1, 0);
    limit.assign(n + 1, 0);
    arr.assign(n + 1, {0, 0});

    for (int i = 1;i <= n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++) {
        for (int j = limit[i - 1];j < i;j++) {
            if (arr[i].first - arr[j].first < s) break;
            limit[i] = j;
        }
    }

    for (int i = 1;i <= n;i++)
        dp[i] = max(dp[i - 1], dp[limit[i]] + arr[i].second);
    cout << dp[n];
    return 0;
}