#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> arr;
vector<int> visited, parent;

void dfs(int now){
    for(auto next : arr[now]){
        if(visited[next]) continue;
        visited[next] = 1;
        dfs(next);
        parent[next] = now;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n + 1, vector<int>());
    visited.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    visited[1] = 1;
    dfs(1);
    
    for(int i = 2;i <= n;i++) cout << parent[i] << "\n";
    return 0;
}