#include <iostream>

using namespace std;

int n, t, c, ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = n;i;i /= 2) t += i / 2;
    for (int i = n;i;i /= 5) t -= i / 5;

    for (int i = 3;i <= n;i++) {
        c = i;
        while (c % 2 == 0) c /= 2;
        while (c % 5 == 0) c /= 5;

        ans = ans * c % 10;
    }
    while (t--)
        ans = ans * 2 % 10;

    cout << ans;
    return 0;
}