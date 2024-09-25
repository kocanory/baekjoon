#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
string s1, s2;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    dp.assign(s1.length(), vector<int>(s2.length()));
    
    for(int i = 1;i < s1.length();i++){
        for(int j = 1;j < s2.length();j++)
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
    }
    cout << ans << "\n";
    return 0;
}