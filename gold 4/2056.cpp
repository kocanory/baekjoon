#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, backCount, back, ans;
vector<int> t, inDeg, result;
unordered_map<int, vector<int>> graph;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    t.assign(n + 1, 0);
    inDeg.assign(n + 1, 0);
    result.assign(n + 1, 0);
    
    for(int i = 1;i <= n;i++){
        cin >> t[i] >> backCount;
        result[i] = t[i];
        inDeg[i] = backCount;
        if(!backCount) q.push(i);
        while(backCount--){
            cin >> back;
            graph[back].push_back(i);
        }
    }

    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto &next : graph[now]){
            result[next] = max(result[next], result[now] + t[next]);
            inDeg[next]--;
            if(!inDeg[next]) q.push(next);
        }
    }
    for(int i = 1;i <= n;i++) ans = max(ans, result[i]);
    cout << ans << "\n";
    return 0;
}