#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<int> arr;
vector<vector<int>> dp;

int dfs(int left, int right, bool turn) {
    if (left > right) return 0;
    if (dp[left][right]) return dp[left][right];
    if (turn)
        return dp[left][right] = max(arr[left] + dfs(left + 1, right, !turn), arr[right] + dfs(left, right - 1, !turn));
    return dp[left][right] = min(dfs(left + 1, right, !turn), dfs(left, right - 1, !turn));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        arr = vector(n, 0);
        dp = vector(n, vector(n, 0));

        for (int i = 0;i < n;i++) cin >> arr[i];
        cout << dfs(0, n - 1, true) << "\n";
    }
    return 0;
}