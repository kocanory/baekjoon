#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

int n, m, t, d, ans = -1;
vector<string> arr;
vector<vector<int>> dist, up, down;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int convHeight(char c) {
    if (isupper(c)) return c - 'A';
    return c - 'a' + 26;
}

vector<vector<int>> dijkstra(int flag) {
    priority_queue<tuple<int, int, int>> pq;
    dist.assign(n, vector(m, (int)1e9));
    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        cost = -cost;
        if (dist[x][y] < cost) continue;

        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int val = convHeight(arr[x][y]) - convHeight(arr[nx][ny]), ncost;
            if (abs(val) > t) continue;
            if (flag) {
                if (val <= 0) ncost = cost + 1;
                else ncost = cost + pow(val, 2);
            }
            else {
                if (val >= 0) ncost = cost + 1;
                else ncost = cost + pow(val, 2);
            }
            if (dist[nx][ny] > ncost) {
                dist[nx][ny] = ncost;
                pq.push({-ncost, nx, ny});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t >> d;
    arr.assign(n, "");

    for (auto &a : arr) cin >> a;

    up = dijkstra(0), down = dijkstra(1);

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++) {
            if (up[i][j] + down[i][j] > d) continue;
            ans = max(ans, convHeight(arr[i][j]));
        }
    cout << ans;
    return 0;
}