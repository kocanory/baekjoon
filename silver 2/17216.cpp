#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for (int &a : arr) cin >> a;
    dp = arr;

    for (int i = 1;i < n;i++) {
        for (int j = 0;j < i;j++)
            if (arr[j] > arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}