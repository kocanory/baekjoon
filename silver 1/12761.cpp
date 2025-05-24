#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, b, n, m;
vector<int> dp(100001, -1);
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b >> n >> m;
    
    dp[n] = 0;
    q.push(n);
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        
        vector <int> next = {
            now + 1,
            now - 1,
            now + a,
            now - a,
            now + b,
            now - b,
            now * a,
            now * b
        };
        
        bool flag = false;
        for(auto nxt : next)
            if(nxt >= 0 && nxt <= 100000 && dp[nxt] == -1){
                q.push(nxt);
                dp[nxt] = dp[now] + 1;
                
                if(nxt == m){
                    flag = true;
                    break;
                }
            }
        if(flag) break;
    }
    
    cout << dp[m];
    return 0;
}