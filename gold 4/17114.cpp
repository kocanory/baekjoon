#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int r, c, t, sum = 0;
vector<vector<int>> arr, dust;
vector<int> cleaner;

void work_cleaner(int num) {
    int row = cleaner[num], idx = 0;

    pair<int, int> now = {row, 1};
    int back = 0;
    while(now.first != row || now.second != 0) {
        swap(back, arr[now.first][now.second]);

        int nx = now.first + dx[idx], ny = now.second + dy[idx];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c)
            num == 0 ? idx = (idx + 1) % 4 : idx = (idx + 3) % 4;
        now.first += dx[idx];
        now.second += dy[idx];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;
    arr.assign(r, vector<int>(c));
    dust.assign(r, vector<int>(c));
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == -1) cleaner.push_back(i);
        }
    }

    while(t--) {
        for(int i = 0;i < r;i++) {
            for(int j = 0;j < c;j++) {
                if(arr[i][j] / 5 > 0) {
                    int cnt = 0;
                    for(int d = 0;d < 4;d++) {
                        int nx = i + dx[d], ny = j + dy[d];
                        if(nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == -1) continue;
                        dust[nx][ny] += arr[i][j] / 5;
                        cnt++;
                    }
                    arr[i][j] -= arr[i][j] / 5 * cnt;
                }
            }
        }
        for(int i = 0;i < r;i++) {
            for(int j = 0;j < c;j++) {
                arr[i][j] += dust[i][j];
                dust[i][j] = 0;
            }
        }
        work_cleaner(0);
        work_cleaner(1);
    }

    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            if(arr[i][j] <= 0) continue;
            sum += arr[i][j];
        }
    }
    cout << sum << "\n";
    return 0;
}