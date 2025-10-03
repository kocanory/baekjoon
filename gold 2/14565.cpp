#include <iostream>

using namespace std;

typedef long long ll;

ll n, a, m;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll xgcd(ll a, ll b) {
    ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;

    while (true) {
        if (r2 == 0) return s1;
        ll q = r1 / r2, r = r1 - q * r2, s = s1 - q * s2, t = t1 - q * t2;
        r1 = r2, r2 = r, s1 = s2, s2 = s, t1 = t2, t2 = t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> a;

    if (gcd(a, n) != 1)
        m = -1;
    else {
        m = xgcd(a, n);
        while (m <= 0)
            m += n;
    }
    cout << n - a << " " << m;
    return 0;
}