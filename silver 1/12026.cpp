#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
string s;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    dp.assign(n, 1e9);
    dp[0] = 0;
    
    for(int i = 1;i < n;i++)
        for(int j = 0;j < i;j++)
            if((s[j] == 'B' && s[i] == 'O') || (s[j] == 'O' && s[i] == 'J') || (s[j] == 'J' && s[i] == 'B'))
                dp[i] = min(dp[i], dp[j] + (int)pow(i - j, 2));

    cout << (dp[n - 1] == 1e9 ? -1 : dp[n - 1]);
    return 0;
}