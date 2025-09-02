#include <iostream>
#include <vector>

using namespace std;

int n, m, k, ans = 0;
vector<string> arr;
string word;
vector<vector<vector<int>>> dp;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int idx, int x, int y) {
    if (idx == word.size() - 1) return 1;
    
    int &ret = dp[x][y][idx];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 1;i <= k;i++) {
        for (auto[dx, dy] : dir) {
            int nx = x + dx * i, ny = y + dy * i;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == word[idx + 1])
                ret += dfs(idx + 1, nx, ny);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    arr.assign(n, "");

    for (int i = 0;i < n;i++) cin >> arr[i];
    cin >> word;

    dp.assign(n, vector(m, vector(word.size(), -1)));

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            if (arr[i][j] == word[0])
                ans += dfs(0, i, j);

    cout << ans;
    return 0;
}