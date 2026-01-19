#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector arr(5, vector<int>(5));
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<string> s;

void dfs(int x, int y, string val) {
    if (val.size() == 6) {
        s.insert(val);
        return;
    }

    for (auto [dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        dfs(nx, ny, val + char(arr[nx][ny] + '0'));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0;i < 5;i++)
        for (int j = 0;j < 5;j++)
            cin >> arr[i][j];

    for (int i = 0;i < 5;i++)
        for (int j = 0;j < 5;j++)
            dfs(i, j, to_string(arr[i][j]));

    cout << s.size();
}