#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, ans = 0;
vector<vector<int>> arr;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<int> dice(7);

int reverseDir(int d) {
    if (d == 0) return 1;
    if (d == 1) return 0;
    if (d == 2) return 3;
    if (d == 3) return 2;
}

int changeDir(int d, int val) {
    if (val > 0) {
        if (d == 0) return 2;
        if (d == 1) return 3;
        if (d == 2) return 1;
        if (d == 3) return 0;
    }
    else if (val < 0) {
        if (d == 0) return 3;
        if (d == 1) return 2;
        if (d == 2) return 0;
        if (d == 3) return 1;
    }
    return d;
}

void rollDice(int d) {
    int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];

    if (d == 0) {
        dice[1] = d4;
        dice[3] = d1;
        dice[4] = d6;
        dice[6] = d3;
    }
    else if (d == 1) {
        dice[1] = d3;
        dice[3] = d6;
        dice[4] = d1;
        dice[6] = d4;
    }
    else if (d == 2) {
        dice[1] = d2;
        dice[2] = d6;
        dice[5] = d1;
        dice[6] = d5;
    }
    else {
        dice[1] = d5;
        dice[2] = d1;
        dice[5] = d6;
        dice[6] = d2;
    }
}

void bfs(int i, int j) {
    vector check(n, vector(m, false));
    queue<pair<int, int>> q;

    q.push({i, j});
    check[i][j] = true;
    int num = arr[i][j], cnt = 1;

    while (!q.empty()) {
        auto[x, y] = q.front(); q.pop();
        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] == num && !check[nx][ny]) {
                    check[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }
    ans += (num * cnt);
}

void solve() {
    int x = 0, y = 0, d = 0;
    for (int i = 0;i < k;i++) {
        int nx = x + dir[d].first, ny = y + dir[d].second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            d = reverseDir(d);
            nx = x + dir[d].first, ny = y + dir[d].second;
        }

        bfs(nx, ny);
        rollDice(d);
        d = changeDir(d, dice[6] - arr[nx][ny]);
        x = nx, y = ny;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    arr = vector(n, vector(m, 0));

    for (int i = 1;i <= 6;i++) dice[i] = i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    solve();
    return 0;
}