#include <iostream>
#include <vector>

using namespace std;

int n, sum;
vector<pair<int, int>> arr;
vector<vector<int>> dp;

int dfs(int idx, int price) {
    if (price < 0) return 0;
    if (idx == n) return price == 0;
    int &ret = dp[idx][price];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0;i <= arr[idx].second;i++)
        ret = ret || dfs(idx + 1, price - arr[idx].first * i);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        cin >> n;
        arr.assign(n, {0, 0});
        sum = 0;

        for (auto &[a, b] : arr) {
            cin >> a >> b;
            sum += a * b;
        }
        dp.assign(n, vector(sum / 2 + 1, -1));
        sum % 2 ? cout << 0 << "\n" :cout << dfs(0, sum / 2) << "\n";
    }

    return 0;
}