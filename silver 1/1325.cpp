#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m, max_cnt;
unordered_map<int, vector<int>> tree;
vector<bool> visited;
vector<int> ans;

void bfs(int s){
    queue<int> q;
    q.push(s);
    
    visited.assign(n + 1, false);
    visited[s] = true;
    int cnt = 1;
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int next : tree[now]){
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                cnt++;
            }
        }
    }
    max_cnt = max(cnt, max_cnt);
    ans[s] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    ans.assign(n + 1, 0);
    
    while(m--){
        int a, b;
        cin >> a >> b;
        tree[b].push_back(a);
    }
    
    for(int i = 1;i <= n;i++) bfs(i);
    for(int i = 1;i <= n;i++)
        if(ans[i] == max_cnt)
            cout << i << " ";
    return 0;
}