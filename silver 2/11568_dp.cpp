#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1;
vector<int> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 1);
    dp = arr;

    for(int &a : arr) cin >> a;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i;j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(dp[i], ans);
    }
    cout << ans;
}