#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector<string> a;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s >> n;
    a.assign(n, "");
    dp.assign(s.size() + 1, false);
    
    for(auto &w : a) cin >> w;
    
    for(int i = 0;i < s.size();i++){
        if(dp[i] || i == 0){
            for(auto &w : a){
                if(i + w.size() > s.size()) continue;
                
                bool flag = true;
                if(w != s.substr(i, w.size())) flag = false;
                if(flag) dp[i + w.size()] = true;
            }
        }
    }
    cout << dp[s.size()];
    return 0;
}