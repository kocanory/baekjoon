#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int t;
ll n;
int dp[100];

ll solve(ll price) {
    if (!price) return 0;
    return dp[price % 100] + solve(price / 100);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 1;i < 100;i++) {
        if (i >= 25) dp[i] = min(dp[i - 25], min(dp[i - 10], dp[i - 1])) + 1;
        else if (i >= 10) dp[i] = min(dp[i - 10], dp[i - 1]) + 1;
        else dp[i] = i;
    }

    while (t--) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}