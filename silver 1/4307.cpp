#include <iostream>

using namespace std;

int t, l, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> l >> n;

        int minTime = 0, maxTime = 0;
        while (n--) {
            int pos;
            cin >> pos;

            minTime = max(minTime, min(pos, l - pos));
            maxTime = max(maxTime, max(pos, l - pos));
        }
        cout << minTime << " " << maxTime << "\n";
    }

    return 0;
}