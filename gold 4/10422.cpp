#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<long long> dp(5001, 0);

void init() {
    dp[0] = 1;
    for (int i = 2;i <= 5000;i += 2)
        for (int j = 2;j <= i;j += 2) {
            dp[i] += (dp[i - j] * dp[j - 2]);
            dp[i] %= 1000000007;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}