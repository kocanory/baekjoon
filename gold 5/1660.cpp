#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 1, ball = 1, dum = 1;
vector<int> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp.assign(n + 1, 1e9);

    while (dum <= n) {
        arr.push_back(dum);
        dp[dum] = 1;

        ball += ++cnt;
        dum += ball;
    }

    for (auto a : arr)
        for (int i = a;i <= n;i++)
            dp[i] = min(dp[i], dp[i - a] + 1);

    cout << dp[n];

    return 0;
}