#include <iostream>

using namespace std;

int n, x, zNum, aNum, mid, remain;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    if (n > x || x > 26 * n) {
        cout << "!";
        exit(0);
    }

    for (zNum = 0; zNum <= n; zNum++) {
        if (n - zNum > x - 26 * zNum) {
            remain = x - 26 * (zNum - 1);
            break;
        }
    }

    zNum--;
    aNum = n - zNum - 1;
    mid = remain - aNum;

    for (int i = 0;i < aNum;i++)
        cout << 'A';

    if (zNum != n)
        cout << char('A' + mid - 1);

    for (int i = 0;i < zNum;i++)
        cout << 'Z';

    return 0;
}