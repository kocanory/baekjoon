#include <iostream>
#include <vector>

using namespace std;

string s, e;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s >> e;
    s = " " + s;
    e = " " + e;
    
    dp.assign(s.size(), vector<int>(e.size()));
    
    for(int i = 0;i < s.size();i++)
        for(int j = 0;j < e.size();j++){
            if(i == 0 && j == 0) continue;
            if(i == 0){
                dp[i][j] = j;
                continue;
            }
            if(j == 0){
                dp[i][j] = i;
                continue;
            }
            if(s[i] == e[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    cout << dp[s.size() - 1][e.size() - 1];
    return 0;
}