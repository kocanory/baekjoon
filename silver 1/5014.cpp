#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int f, s, g, u, d;
vector dp(1000001, -1);
queue<int> q;

void bfs(){
    q.push(s);
    dp[s] = 0;
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(now == g) break;
        if(now + u <= f){
            if(dp[now + u] == -1){
                dp[now + u] = dp[now] + 1;
                q.push(now + u);
            }
        }
        if(now - d >= 1){
            if(dp[now - d] == -1){
                dp[now - d] = dp[now] + 1;
                q.push(now - d);
            }
        }
    }
    cout << (dp[g] == -1 ? "use the stairs" : to_string(dp[g]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> f >> s >> g >> u >> d;
    bfs();
    return 0;
}