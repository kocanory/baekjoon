#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map<int, vector<int>> graph;
    vector<int> t(n + 1);
    vector<int> dp(n + 1, 0);
    vector<int> inDeg(n + 1, 0);
    queue<int> q;
    
    
    for(int i = 0;i < n;i++){
        cin >> t[i + 1];
        
        while(true){
            int input;
            cin >> input;
            if(input == -1) break;
            graph[input].push_back(i + 1);
            inDeg[i + 1]++;
        }
    }
    
    for(int i = 1;i <= n;i++)
        if(inDeg[i] == 0) q.push(i);
        
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto next : graph[now]){
            dp[next] = max(dp[next], dp[now] + t[now]);
            inDeg[next]--;
            if(inDeg[next] == 0) q.push(next);
        }
    }
    
    for(int i = 1;i <= n;i++)
        cout << dp[i] + t[i] << "\n";
    return 0;
}