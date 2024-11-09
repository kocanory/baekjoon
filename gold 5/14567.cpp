#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m;
vector<int> inDeg, dp;
unordered_map<int, vector<int>> tree;
queue<int> q;

void bfs(){
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto &next : tree[now]){
            inDeg[next]--;
            if(inDeg[next] == 0){
                dp[next] = max(dp[next], dp[now] + 1);
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    inDeg.assign(n + 1, 0);
    dp.assign(n + 1, 0);

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        inDeg[b]++;
    }

    for(int i = 1;i <= n;i++)
        if(!inDeg[i]) {
            q.push(i);
            dp[i] = 1;
        }
    bfs();
    for(int i = 1;i <= n;i++)
        cout << dp[i] << " ";
    return 0;
}