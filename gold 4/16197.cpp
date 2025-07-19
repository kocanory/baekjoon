#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<string> arr;
queue<vector<int>> q;
bool check[20][20][20][20];
vector<pair<int, int>> dir = {{1, 0}, {0, 1},  {-1, 0}, {0, -1}};

int bfs() {
    while (!q.empty()) {
        vector<int> now = q.front(); q.pop();
        int x1 = now[0], y1 = now[1], x2 = now[2], y2 = now[3], cnt = now[4];
        if (cnt >= 10) return -1;

        for (auto [dx, dy] : dir) {
            int nx1 = x1 + dx, ny1 = y1 + dy,  nx2 = x2 + dx, ny2 = y2 + dy;
            bool flag1 = nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m, flag2 = nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m;

            if (!flag1 && !flag2) {
                if (arr[nx1][ny1] == '#') {
                    nx1 = x1, ny1 = y1;
                }
                if (arr[nx2][ny2] == '#') {
                    nx2 = x2, ny2 = y2;
                }
                if (check[nx1][ny1][nx2][ny2]) continue;
                check[nx1][ny1][nx2][ny2] = true;
                q.push({nx1, ny1, nx2, ny2, cnt + 1});
            }
            else if (flag1 && flag2) continue;
            else return cnt + 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");

    vector<int> start;
    for (int i = 0;i < n ;i++) {
        cin >> arr[i];
        for (int j = 0 ;j < m;j++)
            if (arr[i][j] == 'o') {
                start.push_back(i);
                start.push_back(j);
            }
    }
    start.push_back(0);
    q.push(start);
    check[start[0]][start[1]][start[2]][start[3]] = true;
    cout << bfs();
    return 0;
}