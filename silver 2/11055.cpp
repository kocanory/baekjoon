#include <iostream>
#include <vector>


using namespace std;

int n, ans;
vector<int> arr, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, 0);

    for (int i = 0;i <n ;i++) {
        cin >> arr[i];
        dp[i] = arr[i];
        for (int j = 0;j < i;j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j]+arr[i]);
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    return 0;
}