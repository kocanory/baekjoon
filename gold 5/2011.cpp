#include <iostream>
#include <vector>
#include <string>

using namespace std;

string n;
vector<int> dp(5010);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    int len = n.length();
    n = '0' + n;
    
    dp[0] = 1;
    for(int i = 1;i <= len;i++){
        if(n[i] >= '1' && n[i] <= '9') dp[i] = (dp[i - 1] + dp[i]) % 1000000;
        if(i >= 2){
            int num = stoi(n.substr(i - 1, 2));
            if(num >= 10 && num <= 26) dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
    }
    cout << dp[len] << "\n";
    return 0;
}