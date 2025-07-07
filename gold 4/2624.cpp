#include <iostream>
#include <vector>

using namespace std;

int t, k, p, n;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t >> k;
    dp.assign(t + 1, 0);
    dp[0] = 1;
    
    while(k--){
        cin >> p >> n;
        for(int i = t;i > 0;i--)
            for(int j = 1;j <= n;j++){
                if(i - p * j < 0) break;
                dp[i] += dp[i - p * j];
            }
    }
    cout << dp[t];
    return 0;
}