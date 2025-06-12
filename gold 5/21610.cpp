#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

int n, m, d, s, ans = 0;
vector<vector<int>> arr;
vector<pair<int, int>> cloud;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    cloud.push_back({n - 1, 0});
    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 2, 0});
    cloud.push_back({n - 2, 1});

    while (m--) {
        cin >> d >> s;

        set<pair<int, int>> check;

        for (auto &[x, y] : cloud) {
            x = ((x + dir[d - 1].first * s) % n + n) % n;
            y = ((y + dir[d - 1].second * s) % n + n) % n;

            arr[x][y]++;
            check.insert({x, y});
        }

        for (auto &[x, y] : cloud) {
            int cnt = 0;
            for (int i = 1;i < dir.size();i += 2) {
                int nx = x + dir[i].first, ny = y + dir[i].second;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || !arr[nx][ny]) continue;
                cnt++;
            }
            arr[x][y] += cnt;
        }

        cloud.clear();
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (arr[i][j] >= 2 && check.find({i, j}) == check.end()) {
                    arr[i][j] -= 2;
                    cloud.push_back({i, j});
                }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += arr[i][j];
    cout << ans;
    return 0;
}