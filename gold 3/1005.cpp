#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> building(n + 10);
        vector<int> dp(n + 10);
        vector<int> count(n + 10);
        unordered_map<int, vector<int>> um;
        
        for(int i = 1;i <= n;i++) cin >> building[i];
        
        for(int i = 0;i < k;i++) {
            int first, second;
            cin >> first >> second;
            um[first].push_back(second);
            count[second]++;
        }
        
        queue<int> q;
        
        for(int i = 1;i <= n;i++){
            if(count[i] == 0) q.push(i);
            dp[i] = building[i];
        }
        
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(auto next : um[now]){
                dp[next] = max(dp[next], dp[now] + building[next]);
                count[next]--;
                if(count[next] == 0) q.push(next);
            }
        }
        
        int w;
        cin >> w;
        cout << dp[w] << "\n";
    }
    return 0;
}