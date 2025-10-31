#include <iostream>
#include <vector>

using namespace std;

int n, mod = 10000003;
vector<int> arr;
vector<vector<int>> dp;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector<int>(100001));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][arr[i]] = 1;
    }

    for (int i = 1;i < n;i++) {
        for (int j = 1;j <= 100000;j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;

            int cop = gcd(arr[i], j);
            dp[i][cop] += dp[i - 1][j];
            dp[i][cop] %= mod;
        }
    }
    cout << dp[n - 1][1];
    return 0;
}