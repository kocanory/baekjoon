#include <iostream>
#include <vector>

using namespace std;

string s;
int n, answer = 0;
vector<int> dp(1010, 0);

void palindrome(){
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            if(s[i] == s[j]){
                dp[j]++;
                for(int k = j + 1;k < n;k++){
                    dp[j] += dp[k];
                    dp[j] %= 10007;
                }
            }
        }
    }
    
    for(int i = 0;i < n;i++) 
    {
        answer += dp[i];
        answer %= 10007;
    }
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    n = s.length();
    palindrome();
    return 0;
}