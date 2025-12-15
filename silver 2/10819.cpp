#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> arr, check;

void dfs(int cnt, int val, int sum) {
    if (cnt == n) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0;i < n;i++) {
        if (!check[i]) {
            check[i] = true;
            dfs(cnt + 1, arr[i], cnt ? sum + abs(val - arr[i]) : 0);
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    check.assign(n, 0);

    for (int &a : arr) cin >> a;
    dfs(0, 0, 0);
    cout << ans;

    return 0;
}