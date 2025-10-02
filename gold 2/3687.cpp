#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<long long> dp(101, 1e20);
vector minNum = {0, 0, 1, 7, 4, 2, 0, 8};

string maxNum(string num, int cnt) {
    if (cnt == 0 || cnt == 3) {
        if (cnt == 3) num = "7" + num;
        return num;
    }
    return maxNum("1" + num, cnt - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 9, dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 6, dp[7] = 8;

    for (int i = 8;i <= 100;i++)
        for (int j = 2;j <= 7;j++)
            dp[i] = min(dp[i], dp[i - j] * 10 + minNum[j]);

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << " " << maxNum("", n) << "\n";
    }

    return 0;
}