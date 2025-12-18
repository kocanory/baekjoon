#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
vector<vector<int>> arr;
vector<bool> check;

void dfs(int now, int cnt, int cost, int start) {
    if (cnt == n - 1) {
        if (arr[now][start])
            ans = min(ans, cost + arr[now][start]);
        return;
    }
    for (int i = 0;i <n;i++) {
        if (arr[now][i] && !check[i]) {
            check[i] = true;
            dfs(i, cnt + 1, cost + arr[now][i], start);
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, vector(n, 0));
    check.assign(n, false);

    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cin >> arr[i][j];

    for (int i = 0;i <n;i++) {
        check[i] = true;
        dfs(i, 0, 0, i);
        check[i] = false;
    }
    cout << ans;
    return 0;
}