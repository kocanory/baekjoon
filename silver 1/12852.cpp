#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp, track;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dp.assign(n + 1, 0);
    track.assign(n + 1, 0);
    
    for(int i = 2;i <= n;i++){
        dp[i] = dp[i - 1] + 1;
        track[i] = i - 1;
        
        if(i % 2 == 0 && dp[i / 2] + 1 < dp[i]){
            dp[i] = dp[i / 2] + 1;
            track[i] = i / 2;
        }
        
        if(i % 3 == 0 && dp[i / 3] + 1 < dp[i]){
            dp[i] = dp[i / 3] + 1;
            track[i] = i / 3;
        }
    }
    
    cout << dp[n] << "\n";
    while(true){
        cout << n << " ";
        if(n == 1) break;
        n = track[n];
    }
    return 0;
}