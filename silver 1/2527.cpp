#include <iostream>

using namespace std;

int x1, y1, p1, q1, x2, y2, p2, q2, xl, xr, yb, yt, xdiff, ydiff;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0;i < 4;i++) {
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
        xl = max(x1, x2);
        xr = min(p1, p2);
        yb = max(y1, y2);
        yt = min(q1, q2);

        xdiff = xr - xl;
        ydiff = yt - yb;
        if (xdiff > 0 && ydiff > 0) cout << 'a' << "\n";
        else if (xdiff < 0 || ydiff < 0) cout << 'd' << "\n";
        else if (xdiff == 0 && ydiff == 0) cout << 'c' << "\n";
        else cout << 'b' << "\n";
    }

    return 0;
}