#include <iostream>
#include <vector>

using namespace std;

int n, m, money;
vector<vector<int>> arr, dp, trace;

int dfs(int now, int com) {
    if (com == 0) return 0;
    int &ret = dp[now][com];
    if (ret != -1) return ret;

    for (int i = 0;i <= now;i++) {
        int val = arr[now - i][com] + dfs(i, com - 1);
        if (ret < val) {
            ret = val;
            trace[now][com] = now - i;
        }
    }
    return ret;
}

void backtrack(int now, int com) {
    if (com == 0) return;
    backtrack(now - trace[now][com], com - 1);
    cout << trace[now][com] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n + 1, vector(m + 1, 0));
    dp.assign(n + 1, vector(m + 1, -1));
    trace.assign(n + 1, vector(m + 1, 0));

    for (int i = 1;i <= n;i++) {
        cin >> money;
        for (int j = 1;j <= m;j++)
            cin >> arr[i][j];
    }

    cout << dfs(n, m) << "\n";
    backtrack(n, m);
    return 0;
}