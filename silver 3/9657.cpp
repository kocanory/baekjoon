#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(1001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp[1] = dp[3] = dp[4] = 1;

    for (int i = 5;i <= 1000;i++) 
        if (!(dp[i - 1] && dp[i - 3] && dp[i - 4])) dp[i] = 1;

    cout << (dp[n] ? "SK" : "CY");
    return 0;
}