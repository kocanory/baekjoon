#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, answer = 0;
unordered_map<int, vector<int>> tree;
vector<vector<int>> dp;
vector<bool> check;

void dfs(int node){
    check[node] = true;
    dp[node][0] = 1;
    for(auto c : tree[node]){
        if(check[c]) continue;
        dfs(c);
        dp[node][1] += dp[c][0];
        dp[node][0] += min(dp[c][0], dp[c][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    check.assign(n + 1, false);
    dp.assign(n + 1, vector<int>(2));
    for(int i = 0;i < n - 1;i++){
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
        tree[c].push_back(p);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]) << "\n";
    return 0;
}