#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, maxNode, maxDist;
vector<bool> visited;
unordered_map<int, vector<pair<int, int>>> tree;

void dfs(int node, int dist){
    if(visited[node]) return;
    visited[node] = true;
    if(maxDist < dist){
        maxNode = node;
        maxDist = dist;
    }
    for(auto &next : tree[node])
        dfs(next.first, dist + next.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    visited.assign(n + 1, false);

    for(int i = 0;i < n - 1;i++){
        int parent, child, dist;
        cin >> parent >> child >> dist;
        tree[parent].emplace_back(child, dist);
        tree[child].emplace_back(parent, dist);
    }

    dfs(1, 0);
    visited.assign(n + 1, false);
    maxDist = 0;

    dfs(maxNode, 0);
    cout << maxDist << "\n";
    return 0;
}