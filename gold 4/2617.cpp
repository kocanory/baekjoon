#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, upper, lower, ans;
unordered_map<int, vector<int>> up, down;
vector<bool> visited;

void findUpper(int now){
    visited[now] = true;
    for(auto &next : up[now]){
        if(visited[next]) continue;
        upper++;
        findUpper(next);
    }
}

void findLower(int now){
    visited[now] = true;
    for(auto &next : down[now]){
        if(visited[next]) continue;
        lower++;
        findLower(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        down[a].push_back(b);
        up[b].push_back(a);
    }
    
    for(int i = 1;i <= n;i++){
        upper = lower = 0;
        visited.assign(n + 1, false);
        findUpper(i);
        visited.assign(n + 1, false);
        findLower(i);
        if(upper > n / 2 || lower > n / 2) ans++;
    }
    cout << ans << "\n";
    return 0;
}