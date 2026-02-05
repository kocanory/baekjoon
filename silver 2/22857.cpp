#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 0;
vector<int> arr;
vector<vector<int>> dp;

int dfs(int idx, int del, int len) {
    if (idx < 0) return len;

    int &res = dp[idx][del];
    if (res) return res;

    if (!(arr[idx] % 2)) res = dfs(idx - 1, del, len + 1);
    else if (del < k) res = dfs(idx - 1, del + 1, len);
    else if (del == k) return len;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, 0);
    dp.assign(n, vector(k + 1, 0));

    for (int &a : arr) cin >> a;
    for (int i = n - 1;i >= 0;i--)
        if (!(arr[i] % 2))
            ans = max(ans, dfs(i, 0, 0));
    cout << ans;
    return 0;
}