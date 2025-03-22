#include <iostream>
#include <vector>

using namespace std;

int n, mod = 1000000009;
vector dp(100001, vector<long long>(4));

void init(){
    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    
    for(int i = 4;i <= 100000;i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        cout << (dp[num][1] + dp[num][2] + dp[num][3]) % mod << "\n";
    }
    return 0;
}