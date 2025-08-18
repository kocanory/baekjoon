#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, hx, hy, ex, ey;
vector<vector<int>> arr;
vector<vector<vector<bool>>> check;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs() {
    queue<tuple<int, int, int, int>> q;
    q.push({0, hx - 1, hy - 1, 1});
    check[1][hx - 1][hy - 1] = true;

    while (!q.empty()) {
        auto [cnt, x, y, wall] = q.front(); q.pop();
        if (x == ex - 1 && y == ey - 1) return cnt;

        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] && wall && !check[wall - 1][nx][ny]) {
                    check[wall - 1][nx][ny] = true;
                    q.push({cnt + 1, nx, ny, wall - 1});
                }
                if (!arr[nx][ny] && !check[wall][nx][ny]) {
                    check[wall][nx][ny] = true;
                    q.push({cnt + 1, nx, ny, wall});
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> hx >> hy >> ex >> ey;
    arr = vector(n, vector(m, 0));
    check = vector(2, vector(n, vector(m, false)));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << bfs();
}