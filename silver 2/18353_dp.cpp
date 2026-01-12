#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, lis = 1;
vector<int> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 1);
    dp = arr;

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        for (int j = 0;j < i;j++)
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                lis = max(lis, dp[i]);
            }
    }

    cout << n - lis;
    return 0;
}