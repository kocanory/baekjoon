#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<long long> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, 0);

    for (int i = 0;i < n;i++)  cin >> arr[i];
    dp[1] = 1 + abs(arr[1] - arr[0]);

    for (int i = 2;i < n;i++) {
        long long Min = INT_MAX;
        for (int j = 0;j < i;j++) {
            long long power = (i - j) * (1 + abs(arr[i] - arr[j]));
            Min = min(max(power, dp[j]), Min);
        }
        dp[i] = Min;
    }
    cout << dp[n - 1];
    return 0;
}