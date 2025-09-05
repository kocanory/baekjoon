#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    n = s.size();

    dp.assign(n, vector(n, 0));

    for (int i = 1;i < n;i++) {
        for (int j = 0;j < n - i;j++) {
            if ((s[j] == 'a' && s[j + i] == 't') || (s[j] == 'g' && s[j + i] == 'c'))
                dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
            for (int k = j;k < j + i;k++)
                dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
        }
    }
    cout << dp[0][n - 1];
    return 0;
}