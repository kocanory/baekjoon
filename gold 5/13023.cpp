#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, vector<int>> graph;
vector<bool> visited;
bool flag = false;

void dfs(int count, int node) {
    if(count >= 4) {
        flag = true;
        return;
    }
    for(auto &next : graph[node]) {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(count + 1, next);
        visited[next] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0;i < n && !flag;i++) {
        visited.assign(n, false);
        visited[i] = true;
        dfs(0, i);
    }
    cout << flag << "\n";
    return 0;
}