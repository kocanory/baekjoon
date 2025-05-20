#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, cnt = 0;
vector<int> arr;
unordered_map<int, vector<int>> tree;

void dfs(int cur, int prv, int cnt){
    arr[cur] = cnt;
    
    for(auto nxt : tree[cur]){
        if(prv == nxt) continue;
        dfs(nxt, cur, cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n + 1, 0);
    
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0, 0);
    
    for(int i = 2;i <= n;i++)
        if(tree[i].size() == 1)
            cnt += arr[i];
    
    cout << (cnt % 2 ? "Yes" : "No");
    return 0;
}