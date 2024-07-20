#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> arr, dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    arr.assign(n, 0);
    dp.assign(k + 1, 0);
    
    dp[0] = 1;

    for(int i = 0;i < n;i++) cin >> arr[i];
    
    for(auto &a : arr){
        for(int i = a;i <= k;i++)
            dp[i] += dp[i - a];
    }
    cout << dp[k] << "\n";
    return 0;
}