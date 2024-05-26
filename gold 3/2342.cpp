#include <iostream>
#include <vector>

using namespace std;

int n, answer = 1e9;
vector<int> arr;

vector<vector<int>> dir = {{1, 2, 2, 2, 2}, {3, 1, 3, 4, 3}, {3, 3, 1, 3, 4}, {3, 4, 3, 1, 3}, {3, 3, 4, 3, 1}};
vector<vector<vector<int>>> dp(100000, vector<vector<int>>(5, vector<int>(5, -1)));

int dfs(int cur, int left, int right){
    if(cur >= arr.size()) return 0;
    if(left != 0 && right != 0 && left == right) return 1e9;

    int &val = dp[cur][left][right];
    if(val != -1) return val;

    return val = min(dfs(cur + 1, arr[cur], right) + dir[left][arr[cur]], dfs(cur + 1, left, arr[cur]) + dir[right][arr[cur]]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> n;
        if(n == 0) break;
        arr.push_back(n);
    }

    cout << dfs(0, 0, 0) << "\n";
    return 0;
}