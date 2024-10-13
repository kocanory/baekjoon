#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> hp(3);
vector<vector<vector<int>>> dp(61, vector<vector<int>>(61, vector<int>(61, -1)));
vector<vector<int>> attack = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1}
};

int dfs(int x, int y, int z){
    if(x == 0 && y == 0 && z == 0) return 0;
    else if(x < 0) return dfs(0, y, z);
    else if(y < 0) return dfs(x, 0, z);
    else if(z < 0) return dfs(x, y, 0);
    
    int &res = dp[x][y][z];
    if(res != -1) return res;
    res = INT_MAX;
    for(auto a : attack) res = min(res, dfs(x - a[0], y - a[1], z - a[2]) + 1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0;i < 3;i++) cin >> hp[i];
    cout << dfs(hp[0], hp[1], hp[2]) << "\n";
    return 0;
}