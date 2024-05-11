#include <iostream>
#include <vector>

using namespace std;

int n, m;
string s1, s2;
vector<vector<int>> dp;

void lcs(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }  
}

string backtracking(int i, int j){
    if(i == 0 || j == 0) return "";
    else if(s1[i] == s2[j]) return backtracking(i - 1, j - 1) + s1[i];
    
    if(dp[i][j - 1] >= dp[i - 1][j]) return backtracking(i, j - 1);
    else return backtracking(i - 1, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    dp.assign(n + 1, vector<int>(m + 1, 0));
    
    s1 = " " + s1;
    s2 = " " + s2;
    
    lcs();
    
    string answer = backtracking(n, m);
    cout << answer.length() << "\n";
    cout << answer << "\n";

    return 0;
}