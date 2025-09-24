#include <iostream>
#include <vector>

using namespace std;

int n, t, ans = 0;
vector<int> arr;

int dfs(int now) {
    if (now * 2 >= t) {
        ans += arr[now];
        return arr[now];
    }
    int l = dfs(now * 2), r = dfs(now * 2 + 1);
    ans += abs(l - r) + arr[now];
    return max(l, r) + arr[now];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    t = 1 << (n + 1);
    arr.assign(t, 0);

    for (int i = 2;i < t;i++) cin >> arr[i];
    dfs(1);
    cout << ans;
    return 0;
}