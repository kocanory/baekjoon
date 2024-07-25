#include <iostream>
#include <vector>

using namespace std;

int n, k, num;
vector<int> arr, dp(10010, 1e9);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        cin >> num;
        arr.push_back(num);
        dp[num] = 1;
    }
    
    for(auto &a : arr){
        for(int i = a;i <= k;i++)
            dp[i] = min(dp[i], dp[i - a] + 1);
    }
    cout << (dp[k] == 1e9 ? -1 : dp[k]) << "\n";
    return 0;
}