#include <iostream>
#include <vector>

using namespace std;

int n, k, b, ans, cnt;
vector<bool> check;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> b;
    check.assign(n + 1, false);

    for (int i = 0, now;i < b;i++) {
        cin >> now;
        check[now] = true;
    }

    for (int i = 1;i <= k;i++)
        cnt += check[i];
    ans = cnt;

    for (int i = k + 1;i <= n;i++) {
        cnt += check[i] - check[i - k];
        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}