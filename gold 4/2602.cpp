#include <iostream>
#include <vector>

using namespace std;

string r;
vector<string> bridges(2);
vector<vector<vector<int>>> dp;
int ans = 0;

int dfs(int bIdx, int bridge, int rIdx){
    if(rIdx == r.size()) return 1;
    if(bIdx >= bridges[0].size()) return 0;
    int &ret = dp[bIdx][bridge][rIdx];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int i = bIdx;i < bridges[0].size();i++)
        if(r[rIdx] == bridges[bridge][i])
            ret += dfs(i + 1, !bridge, rIdx + 1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r;
    for(int i = 0;i < 2;i++) cin >> bridges[i];
    dp.assign(bridges[0].size(), vector<vector<int>>(2, vector<int>(r.size(), -1)));
    ans = dfs(0, 0, 0) + dfs(0, 1, 0);
    cout << ans;
    return 0;
}