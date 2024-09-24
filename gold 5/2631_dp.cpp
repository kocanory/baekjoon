#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, Max;
vector<int> arr, dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0;i < n;i++) {
        dp[i] = 1;
        for(int j = 0;j <= i;j++) {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        Max = max(Max, dp[i]);
    }
    cout << n - Max << "\n";
    return 0;
}