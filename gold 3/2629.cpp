#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, num;
vector<vector<bool>> dp;
vector<int> arr;

void dfs(int index, int val){
    if(index > n || dp[index][val]) return;
    dp[index][val] = true;
    dfs(index + 1, val + arr[index]);
    dfs(index + 1, abs(val - arr[index]));
    dfs(index + 1, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    arr.assign(n, 0);
    dp.assign(n + 1, vector<bool>(15010, false));
    
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    dfs(0, 0);
    
    cin >> m;
    
    for(int i = 0;i < m;i++){
        cin >> num;
        if(num > 15000) cout << "N ";
        else if (dp[n][num]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}