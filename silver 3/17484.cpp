#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 1e9;
vector<int> dir = {-1, 0, 1};
vector<vector<int>> arr;

int dfs(int x, int y, int b) {
    if (x == n) return 0;
    int ret = 1e9;
    for (int i = 0;i < 3;i++) {
        if (b == i) continue;
        if (y + dir[i] < 0 || y + dir[i] >= m) continue;
        ret = min(ret, dfs(x + 1, y + dir[i], i) + arr[x][y]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector(m, 0));

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            cin >> arr[i][j];
    
    for (int j = 0;j < m;j++)
        ans = min(ans, dfs(0, j, -1));
    
    cout << ans;

    return 0;
}