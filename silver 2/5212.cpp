#include <iostream>
#include <vector>

using namespace std;

int r, c, maxR, minR, maxC, minC;
vector<string> arr, check;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    minR = r, minC = c;
    arr.assign(r, "");

    for (auto &a : arr) cin >> a;
    check = arr;

    for (int i = 0;i < r;i++) {
        for (int j = 0, cnt;j < c;j++) {
            if (arr[i][j] == 'X') {
                cnt = 0;
                for (auto [dx, dy] : dir) {
                    int nx = i + dx, ny = j + dy;
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == '.')
                        cnt++;
                }
                if (cnt >= 3) check[i][j] = '.';
                else {
                    minR = min(minR, i);
                    minC = min(minC, j);
                    maxR = max(maxR, i);
                    maxC = max(maxC, j);
                }
            }
        }
    }

    for (int i = minR; i <= maxR; i++) {
        for (int j = minC; j <= maxC; j++)
            cout << check[i][j];
        cout << "\n";
    }
    return 0;
}