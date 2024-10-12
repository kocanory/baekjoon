#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, ans;
vector<int> arr;
vector<bool> visited;
vector<vector<int>> dp;
unordered_map<int, vector<int>> tree;

void dfs(int now){
    visited[now] = true;
    dp[now][0] = 0;
    dp[now][1] = arr[now];
    for(auto &next : tree[now]){
        if(visited[next]) continue;
        dfs(next);
        dp[now][0] += max(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
        ans = max(dp[now][0], dp[now][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    arr.assign(n + 1, 0);
    visited.assign(n + 1, false);
    dp.assign(n + 1, vector<int>(2));
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}