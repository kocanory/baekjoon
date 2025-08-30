#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int n, sx = -1, sy, ex, ey;
vector<string> arr;
vector<vector<vector<int>>> dp;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<tuple<int, int, int>> q;

vector<int> changeDir(int d) {
    if (d == 0 || d == 1) return {2, 3};
    return {0, 1};
}

void bfs() {
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        if (x == ex && y == ey) continue;
        int nx = x + dir[d].first, ny = y + dir[d].second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (arr[nx][ny] != '*') {
            if (dp[nx][ny][d] > dp[x][y][d]) {
                dp[nx][ny][d] = dp[x][y][d];
                q.push({nx, ny, d});
            }
            if (arr[nx][ny] == '!') {
                for (auto nd : changeDir(d)) {
                    if (dp[nx][ny][nd] > dp[x][y][d] + 1) {
                        dp[nx][ny][nd] = dp[x][y][d] + 1;
                        q.push({nx, ny, nd});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, "");
    dp = vector(n, vector(n, vector<int>(4, 1e9)));

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        for (int j = 0;j < n;j++) {
            if (arr[i][j] == '#'){
                if (sx == -1)
                    sx = i, sy = j;
                else
                    ex = i, ey = j;
            }
        }
    }

    for (int i = 0;i < 4;i++) {
        q.push({sx, sy, i});
        dp[sx][sy][i] = 0;
    }
    bfs();
    cout << *min_element(dp[ex][ey].begin(), dp[ex][ey].end());
    return 0;
}