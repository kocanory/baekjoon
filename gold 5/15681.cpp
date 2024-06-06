#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, r, q;
unordered_map<int, vector<int>> graph, tree;
vector<int> subtree;

void makeTree(int node, int parent){
    for(auto &next : graph[node]){
        if(next != parent){
            tree[node].push_back(next);
            makeTree(next, node);
        }
    }
};

void checkVertex(int v){
    for(auto &next : tree[v]){
        checkVertex(next);
        subtree[v] += subtree[next];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> q;
    subtree.assign(n + 1, 1);
    for(int i = 0;i < n - 1;i++){
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    makeTree(r, -1);
    checkVertex(r);

    for(int i = 0;i < q;i++){
        int v;
        cin >> v;
        cout << subtree[v] << "\n";
    }
    return 0;
}