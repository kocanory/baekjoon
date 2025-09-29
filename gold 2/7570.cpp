#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector<int> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    dp.assign(n + 1, 0);

    for (auto &a : arr) cin >> a;

    for (auto &a : arr) {
        dp[a] = dp[a - 1] + 1;
        cnt = max(cnt, dp[a]);
    }
    cout << n - cnt;
    return 0;
}