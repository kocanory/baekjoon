#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, cnt;
vector<vector<int>> arr, check;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void dfs(int x, int y) {
    check[x][y] = true;
    for (auto [dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || !arr[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> m >> n;
        if (n == 0 && m == 0) break;
        arr.assign(n, vector(m, 0));
        check.assign(n, vector(m, 0));

        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                cin >> arr[i][j];

        cnt = 0;
        for (int i = 0 ;i <n;i++)
            for (int j = 0;j < m;j++)
                if (!check[i][j] && arr[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
        cout << cnt << "\n";
    }
    return 0;
}