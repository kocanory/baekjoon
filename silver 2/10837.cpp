#include <iostream>

using namespace std;

int k, c, m, n, diff, remains;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> c;
    while (c--) {
        cin >> m >> n;

        if (m == n) {
            cout << 1 << "\n";
            continue;
        }

        remains = k - max(m, n), diff = abs(m - n);

        if (m > n)
            cout << (diff - remains <= 2 ? 1 : 0) << "\n";
        else 
            cout << (diff - remains <= 1 ? 1 : 0) << "\n";
    }
    return 0;
}