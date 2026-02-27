#include <iostream>
#include <vector>

using namespace std;

int n, Max;
vector<int> arr, dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) break;

        arr.assign(n, 0);
        dp = arr;

        for (int &a : arr) cin >> a;
        Max = dp[0] = arr[0];

        for (int i = 1;i < n;i++) {
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            Max = max(Max, dp[i]);
        }
        cout << Max << "\n";
    }

    return 0;
}