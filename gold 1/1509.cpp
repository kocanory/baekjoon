#include <iostream>
#include <vector>

using namespace std;

string s;
int n;
vector<vector<bool>> palindrome;
vector<int> dp;

void make_palindrome(){
    for(int i = 1;i <= n;i++) palindrome[i][i] = true;
    for(int i = 1;i < n;i++) if(s[i] == s[i + 1]) palindrome[i][i + 1] = true;
    for(int len = 3; len <= n;len++){
        for(int start = 1;start + len - 1 <= n;start++){
            int end = start + len - 1;
            if(s[start] == s[end] && palindrome[start + 1][end - 1]) palindrome[start][end] = true;
        }
    }
}

void solve(){
    make_palindrome();
    for(int end = 1;end <= n;end++){
        dp[end] = 1e9;
        for(int start = 1;start <= end;start++){
            if(palindrome[start][end])
                dp[end] = min(dp[end], dp[start - 1] + 1);
        }
    }
    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    n = s.length();
    s = " " + s;
    palindrome.assign(n + 1, vector<bool>(n + 1, false));
    dp.assign(n + 1, 0);
    solve();
    return 0;
}