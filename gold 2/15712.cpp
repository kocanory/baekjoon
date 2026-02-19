#include <iostream>

using namespace std;

typedef long long ll;

ll a, r, n, mod;

ll mul(ll num, ll exp) {
    if (exp == 1) return num % mod;
    ll val = mul(num, exp / 2);
    if (exp % 2) return num % mod * val % mod * val % mod % mod;
    return val % mod * val % mod % mod;
}

ll solve(ll num, ll exp) {
    if (exp == 1) return 1;
    ll x = solve(num, exp / 2) % mod, y = (1 % mod + mul(num, exp / 2) % mod) % mod;
    if (exp % 2) return (x % mod * y % mod + mul(num, 2 * (exp / 2)) % mod) % mod;
    return x % mod * y % mod % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> r >> n >> mod;
    if (mod == 1) cout << 0;
    else {
        if (r == 1) cout << (a % mod * n % mod) % mod;
        else cout << a % mod * solve(r, n) % mod % mod;
    }
    return 0;
}