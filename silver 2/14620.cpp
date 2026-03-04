#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> arr, check;

void dfs(int sum, int cnt) {
    if (cnt == 3) {
        ans = min(ans, sum);
        return;
    }

    for (int i = 0;i < n;i++)
        for (int j = 0, f, s;j < n;j++) {
            f = 0, s = 0;
            for (auto [dx, dy] : dir) {
                int nx = i + dx, ny = j + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !check[nx][ny])
                    f++;
            }
            if (f == 4) {
                s = arr[i][j];
                check[i][j] = true;
                for (auto [dx, dy] : dir) {
                    int nx = i + dx, ny = j + dy;
                    s += arr[nx][ny];
                    check[nx][ny] = true;
                }
                dfs(sum + s, cnt + 1);

                for (auto [dx, dy] : dir) {
                    int nx = i + dx, ny = j + dy;
                    check[nx][ny] = false;
                }
                check[i][j] = false;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, vector(n, 0));
    check.assign(n, vector(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    dfs(0, 0);
    cout << ans;
    return 0;
}