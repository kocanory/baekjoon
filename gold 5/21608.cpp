#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> score = {0, 1, 10, 100, 1000};
vector<vector<int>> arr;
unordered_map<int, vector<int>> p;

int n, ans = 0;

void check(int idx) {
    int mFcnt = -1, mCnt = -1, x, y, cnt, fcnt;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[i][j] != 0) continue;

            cnt = 0, fcnt = 0;
            for (auto [dx, dy] : dir) {
                int nx = i + dx, ny = j + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (arr[nx][ny] == 0) cnt++;
                if (find(p[idx].begin(), p[idx].end(), arr[nx][ny]) != p[idx].end())
                    fcnt++;
            }

            if (mFcnt < fcnt) {
                mFcnt = fcnt, mCnt = cnt, x = i, y = j;
            }
            else if (mFcnt == fcnt && mCnt < cnt) {
                mCnt = cnt, x = i, y = j;
            }
            else if (mFcnt == fcnt && mCnt == cnt) {
                if (x > i) {
                    x = i, y = j;
                }
                else if (x == i && y > j) {
                    x = i, y = j;
                }
            }
        }
    }
    arr[x][y] = idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, vector<int>(n, 0));

    for (int i = 0;i < n * n;i++) {
        int idx, num;
        cin >> idx;
        for (int j = 0;j < 4;j++) {
            cin >> num;
            p[idx].push_back(num);
        }
        check(idx);
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int cnt = 0;
            for (auto [dx, dy] : dir) {
                int nx = i + dx, ny = j + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (find(p[arr[i][j]].begin(), p[arr[i][j]].end(), arr[nx][ny]) != p[arr[i][j]].end())
                    cnt++;
            }
            ans += score[cnt];
        }
    }
    cout << ans;
    return 0;
}