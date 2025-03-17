#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> dp;

int solve(int x, int y){
    if(y >= m) return 0;
    if(x >= n) return -1e9;
    if(dp[x][y] != -1) return dp[x][y];
    
    int sum = 0;
    dp[x][y] = solve(x + 1, y);
    for(int i = x;i < n;i++){
        sum += arr[i];
        int temp = solve(i + 2, y + 1) + sum;
        dp[x][y] = max(temp, dp[x][y]);
    }
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, 0);
    dp.assign(n, vector<int>(m, -1));

    for(int i = 0;i <n;i++) cin >> arr[i];
    cout << solve(0, 0) << "\n";
    return 0;
}