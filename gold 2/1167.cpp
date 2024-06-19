#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, maxNode, maxDist;
unordered_map<int, vector<pair<int, int>>> tree;
vector<bool> visited;

void dfs(int node, int dist){
    if(visited[node]) return;
    if(maxDist < dist){
        maxDist = dist;
        maxNode = node;
    }

    visited[node] = true;

    for(auto &next : tree[node]){
        dfs(next.first, dist + next.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    visited.assign(n + 1, false);

    for(int i = 0;i < n;i++){
        int now, dest, dist;
        cin >> now;
        while(true){
            cin >> dest;
            if(dest == -1) break;
            cin >> dist;
            tree[now].push_back({dest, dist});
            tree[dest].push_back({now, dist});
        }
    }
    dfs(1, 0);
    visited.assign(n + 1, false);
    maxDist = 0;

    dfs(maxNode, 0);
    cout << maxDist << "\n";
    return 0;
}