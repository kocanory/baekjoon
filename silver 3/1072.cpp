#include <iostream>

using namespace std;

long long x, y, z, l, r, mid, tmp, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y;
    z = y * 100 / x;

    if (z >= 99) {
        cout << -1;
        exit(0);
    }

    l = 0, r = 1e9;

    while (l <= r) {
        mid = (l + r) / 2;
        tmp = (y + mid) * 100 / (x + mid);

        if (z < tmp) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;

    }
    cout << ans;
    return 0;
}