#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector<vector<int>> dp;

int dfs(int l, int r) {
    if (l >= r) return 0;

    int &ret = dp[l][r];
    if (ret != -1) return ret;

    if ((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c'))
        ret = max(ret, dfs(l + 1, r - 1) + 2);

    for (int i = l;i < r;i++)
        ret = max(ret, dfs(l, i) + dfs(i + 1, r));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    n = s.size();

    dp.assign(n, vector(n, -1));
    cout << dfs(0, n - 1);

    return 0;
}