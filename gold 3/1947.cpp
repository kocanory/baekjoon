#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> dp(1000001);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp[2] = 1, dp[3] = 2;

    for (int i = 4;i <= n;i++)
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % 1000000000;

    cout << dp[n];
    return 0;
}