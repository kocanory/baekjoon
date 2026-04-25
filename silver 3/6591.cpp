#include <iostream>

using namespace std;

typedef long long ll;

ll n, k, ans, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        ans = 1, d = 1;
        for (ll i = n;i > max(n - k, k);i--) {
            ans *= i;
            ans /= d;
            d++;
        }
        cout << ans << "\n";
    }
    return 0;
}