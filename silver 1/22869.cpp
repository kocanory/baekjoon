#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> arr, dp;

int dfs(int now) {
    if (now == n - 1) return dp[now] = 1;

    int &ret = dp[now];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = now + 1;i < n;i++)
        if (k >= (i - now) * (1 + abs(arr[i] - arr[now])))
            ret |= dfs(i);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, 0);
    dp.assign(n, -1);

    for (int i = 0;i < n;i++) cin >> arr[i];

    cout << (dfs(0) ? "YES" : "NO");
    return 0;
}