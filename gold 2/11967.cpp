#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, cnt;
vector<vector<vector<pair<int, int>>>> adj;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> check;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    adj.assign(n + 1, vector(n + 1, vector<pair<int, int>>()));
    check.assign(n + 1, vector<int>(n + 1, 0));

    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a][b].push_back({c, d});
    }

    q.push({1, 1});
    check[1][1] = 2;
    cnt = 1;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [nx, ny] : adj[x][y]) {
            if (!check[nx][ny]) {
                for (auto [dx, dy] : dir) {
                    int tx = nx + dx, ty = ny + dy;
                    if (tx > 0 && tx <= n && ty > 0 && ty <= n && check[tx][ty] == 2) {
                        q.push({tx, ty});
                        break;
                    }
                }
                cnt++;
                check[nx][ny] = 1;
            }
        }
        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx > 0 && nx <= n && ny > 0 && ny <= n && check[nx][ny] == 1) {
                q.push({nx, ny});
                check[nx][ny] = 2;
            }
        }
    }
    cout << cnt;
    return 0;
}