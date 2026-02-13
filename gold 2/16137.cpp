#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<vector<int>>> dist;
vector<tuple<int, int>> cliff;
vector<pair<int, int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void checkCliff() {
    for (auto [x, y] : cliff) {
        int h = 0, v = 0;
        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = dir[i];
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] == 0 || arr[nx][ny] == -1 || arr[nx][ny] >= 2) {
                if (i < 2) h++;
                else v++;
            }
        }
        if (h && v) arr[x][y] = -1;
    }
}

int setTime(int now, int period) {
    while (true) {
        if (now % period == 0) break;
        now++;
    }
    return now;
}

void bfs() {
    queue<tuple<int, int, bool, bool>> q;
    q.push({ 0, 0, false, false });
    dist[0][0][0] = 0;

    while (!q.empty()) {
        auto [x, y, bridge, before] = q.front(); q.pop();
        
        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == -1) continue;
            if (arr[nx][ny] == 1) {
                if (dist[bridge][nx][ny] > dist[bridge][x][y] + 1) {
                    dist[bridge][nx][ny] = dist[bridge][x][y] + 1;
                    q.push({ nx, ny, bridge, false });
                }
            }
            else if (arr[nx][ny] >= 2) {
                if (!before) {
                    int t = setTime(dist[bridge][x][y] + 1, arr[nx][ny]);
                    if (dist[bridge][nx][ny] > t) {
                        dist[bridge][nx][ny] = t;
                        q.push({ nx, ny, bridge, true });
                    }
                }
            }
            else {
                if (!bridge && !before) {
                    int t = setTime(dist[bridge][x][y] + 1, m);
                    if (dist[!bridge][nx][ny] > t) {
                        dist[!bridge][nx][ny] = t;
                        q.push({ nx, ny, true, true });
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(n));
    dist.assign(2, vector<vector<int>> (n, vector<int>(n, 1e9)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                cliff.push_back({ i, j });
        }
    }
    checkCliff();
    bfs();
    cout << min(dist[0][n - 1][n - 1], dist[1][n - 1][n - 1]);
}