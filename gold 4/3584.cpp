#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int t, n;
vector<int> parent, depth;
unordered_map<int, vector<int>> tree;

void dfs(int n){
    for(auto &next : tree[n]){
        depth[next] = depth[n] + 1;
        dfs(next);
    }
}

int checkLCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);

    while(depth[a] > depth[b])
        a = parent[a];

    while(a != b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        parent.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        tree.clear();

        for(int i = 1;i <= n;i++) parent[i] = i;

        for(int i = 0;i < n - 1;i++){
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            parent[b] = a;
        }

        for(int i = 1;i < n;i++){
            if(parent[i] == i)
            {
                dfs(i);
                break;
            }
        }

        int p, c;
        cin >> p >> c;
        cout << checkLCA(p, c) << "\n";
    }
    return 0;
}