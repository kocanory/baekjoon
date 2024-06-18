#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
vector<int> depth;
unordered_map<int, vector<int>> tree;

bool comp(int a, int b){
    return depth[a] > depth[b];
}

int dfs(int node){
    if(tree[node].empty()){
        return depth[node] = 0;
    }

    for(auto &next : tree[node]){
        dfs(next);
    }

    sort(tree[node].begin(), tree[node].end(), comp);
    for(int i = 0;i < tree[node].size();i++){
        depth[node] = max(depth[tree[node][i]] + i + 1, depth[node]);
    }
    return depth[node];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    depth.assign(n, 0);

    for(int i = 0;i < n;i++){
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    cout << dfs(0) << "\n";
    return 0;
}