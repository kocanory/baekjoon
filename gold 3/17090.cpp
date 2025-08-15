#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m, ans = 0;
vector<string> arr;
vector<vector<int>> dp;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
map<char, int> idx = {{'R', 0}, {'D', 1}, {'L', 2}, {'U', 3}};

int dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    int d = idx[arr[x][y]];
    return dp[x][y] = dfs(x + dir[d].first, y + dir[d].second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr = vector<string>(n);
    dp = vector(n, vector(m, -1));

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += dfs(i, j);
    cout << ans;
}