#include <iostream>
#include <vector>

using namespace std;

int m, n, ans = 0;
vector<string> arr;
vector<vector<bool>> check;
vector<pair<int, int>> dir = {{0, 1},{0, -1}, {1, 0}, {-1, 0}};

bool dfs(int x, int y) {
    if (x == m - 1) return true;

    bool flag = false;
    for (auto [dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || check[nx][ny] || arr[nx][ny] == '1') continue;
        check[nx][ny] = true;
        flag = flag || dfs(nx, ny);
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    arr.assign(m, "");
    check.assign(m, vector<bool>(n));

    for (auto &a : arr) cin >> a;
    for (int i = 0;i < n;i++)
        if (arr[0][i] == '0')
            ans = ans || dfs(0, i);
    cout << (ans ? "YES" : "NO");
}