#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<long long> dp(1000001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 1;i <= 1000000;i++){
        for(int j = i;j <= 1000000;j+=i)
            dp[j] += i;
        dp[i] += dp[i-1];
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}