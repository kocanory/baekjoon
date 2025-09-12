#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s1, s2;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s1;
    dp.assign(n + 1, vector(n + 1, 0));

    s2 = s1;
    s1 = " " + s1;
    reverse(s2.begin(), s2.end());
    s2 = " " + s2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[n][n];
    return 0;
}