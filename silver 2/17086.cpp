#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, ans = -1;
vector<pair<int, int>> pos, dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<vector<int>> arr, check;

int bfs(int i, int j) {
    check.assign(n, vector(m, 0));
    queue<tuple<int, int, int>> q;
    q.push({i, j, 0});
    check[i][j] = true;

    while (!q.empty()) {
        auto [x, y, cnt] = q.front(); q.pop();
        if (arr[x][y] == 1) return cnt;
        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny]) continue;
            q.push({nx, ny, cnt+1});
            check[nx][ny] = true;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector(m, 0));

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                pos.push_back({i, j});
        }
    }

    for (auto [i, j] : pos)
        ans = max(ans, bfs(i, j));

    cout << ans;
    return 0;
}