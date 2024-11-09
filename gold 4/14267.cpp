#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m;
vector<int> dp;
unordered_map<int, vector<int>> graph;

void bfs(int x){
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto &next : graph[now]) {
            q.push(next);
            dp[next] += dp[now];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dp.assign(n + 1, 0);
    for(int i = 1;i <= n;i++){
        int p;
        cin >> p;
        graph[p].push_back(i);
    }

    for(int i = 0;i < m;i++){
        int now, w;
        cin >> now >> w;
        dp[now] += w;
    }
    bfs(1);
    for(int i =1 ;i <= n;i++)
        cout << dp[i] << " ";
    return 0;
}