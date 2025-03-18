#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<vector<int>> dp;

int pal(int s, int e){
    if(s >= e) return 0;
    if(dp[s][e] != -1) return dp[s][e];

    if(arr[s] == arr[e]) dp[s][e] = pal(s + 1, e - 1);
    else dp[s][e] = min(pal(s + 1, e), pal(s, e - 1)) + 1;
    return dp[s][e];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector<int>(n, -1));
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout << pal(0, n - 1);
    return 0;
}