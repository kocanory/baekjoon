#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, answer = 1e9;
vector<vector<int>> arr, dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.assign(n + 1, vector<int>(3, 0));
    dp.assign(n + 1, vector<int>(3, 1e9));

    for(int i = 1;i <= n;i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for(int color = 0;color < 3;color++){
        for(int i = 0;i < 3;i++){
            if(i == color) dp[1][i] = arr[1][i];
            else dp[1][i] = 1e9;
        }
        for(int i = 2;i <= n;i++){
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
        }

        for(int i = 0;i < 3;i++){
            if(i == color) continue;
            answer = min(answer, dp[n][i]);
        }
    }

    cout << answer << "\n";

    return 0;
}