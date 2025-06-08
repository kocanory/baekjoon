#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> dp, num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dp.assign(n + 1, 0);
    num.assign((int)log2(n) + 1, 0);
    
    for(int i = 0;i < num.size();i++)
        num[i] = 1 << i;
        
    dp[0] = 1;
    
    for(auto i : num)
        for(int j = i;j <= n;j++){
            dp[j] += dp[j - i];
            dp[j] %= 1000000000;
        }
        
    cout << dp[n];
    return 0;
}