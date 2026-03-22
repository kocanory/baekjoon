#include <iostream>
#include <cmath>

using namespace std;

int t, n, sx, sy, ex, ey, cx, cy, r, ans;
bool s, e;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> sx >> sy >> ex >> ey >> n;
        ans = 0;
        while (n--) {
            cin >> cx >> cy >> r;
            s = sqrt(pow(sx - cx, 2) + pow(sy - cy, 2)) < r, e = sqrt(pow(ex - cx, 2) + pow(ey - cy, 2)) < r;
            if (s != e) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}