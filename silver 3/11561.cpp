#include <iostream>

using namespace std;

unsigned long t, n, l, r, mid, ans;

void solve() {
    l = 1, r = n, ans = 0;

    while (l <= r) {
        mid = (l + r) / 2;
        if (mid * (mid + 1) / 2 <= n) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }

    return 0;
}