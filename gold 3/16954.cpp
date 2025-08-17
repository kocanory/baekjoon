#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> arr(8);
vector<pair<int, int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
queue<pair<int, int>> h, o;
vector check(8, vector(8, false));

void moveH() {
    int size = h.size();
    while (size--) {
        auto [x, y] = h.front(); h.pop();
        if (x == 0 && y == 7) {
            cout << 1;
            exit(0);
        }
        if (arr[x][y] == '#') {
            check[x][y] = false;
            continue;
        }

        h.push({x, y});
        for (auto[dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (!check[nx][ny] && arr[nx][ny] == '.') {
                    check[nx][ny] = true;
                    h.push({nx, ny});
                }
            }
        }
    }
}

void moveO() {
    int size = o.size();
    vector tmp(8, string(8, '.'));
    while (size--) {
        auto [x, y] = o.front(); o.pop();
        int nx = x + 1, ny = y;
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            o.push({nx, ny});
            tmp[nx][ny] = '#';
        }
    }
    arr = tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0;i < 8;i++) {
        cin >> arr[i];
        for (int j = 0;j < 8;j++) {
            if (arr[i][j] == '#') {
                o.push({i, j});
            }
        }
    }

    h.push({7, 0});
    check[7][0] = true;

    while (!h.empty()) {
        moveH();
        moveO();
    }
    cout << 0;
}