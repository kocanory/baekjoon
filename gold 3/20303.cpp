#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m, k;
vector<int> child;
vector<vector<int>> dp;
unordered_map<int, vector<int>> friends;
vector<bool> visited;
vector<pair<int, int>> groups;

void bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root] = true;
    int count = 0, sum = 0;

    while(!q.empty()){
        int now = q.front(); q.pop();
        count++;
        sum += child[now];
        for(auto &next : friends[now]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }

    if(count < k){
        groups.push_back({sum, count});
    }
}

void solve(){
    for(int i = 1;i < groups.size();i++){
        for(int j = 1;j < k;j++){
            if(groups[i].second > j) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - groups[i].second] + groups[i].first);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    child.assign(n + 1, 0);
    visited.assign(n + 1, false);
    dp.assign(n + 1, vector<int>(k + 1));
    groups.push_back({0, 0});

    for(int i = 1;i <= n;i++) cin >> child[i];
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for(int i = 1;i <= n;i++)
        if(!visited[i]) bfs(i);

    solve();
    cout << dp[groups.size() - 1][k - 1] << "\n";
    return 0;
}