#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 1e9);
    dp = arr;

    for (int &a : arr) cin >> a;

    dp[0] = 0;
    for (int i = 1;i < n;i++)
        for (int j = 0;j < i;j++)
            if (j + arr[j] >= i)
                dp[i] = min(dp[i], dp[j] + 1);

    cout << (dp[n - 1] == 1e9 ? -1 : dp[n - 1]);
    return 0;
}