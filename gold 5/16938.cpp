#include <iostream>
#include <vector>

using namespace std;

int n, l, r, x;
vector<int> arr, ans;
int cnt;

void dfs(int now) {
    if (ans.size() >= 2) {
        int sum = 0, Max = 0, Min = 1e9;
        for (auto & a : ans) {
            sum += a;
            Max = max(Max, a);
            Min = min(Min, a);
        }
        if (sum >= l && sum <= r && (Max - Min) >= x) cnt++;
    }
    for (int i = now; i < n;i++) {
        ans.push_back(arr[i]);
        dfs(i + 1);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r >> x;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];
    dfs(0);
    cout << cnt << '\n';
    return 0;
}