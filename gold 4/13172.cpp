#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;

ll a, b, m, ans = 0, mod = 1000000007;

ll f(ll x, ll y){
    if(y == 1) return x;
    if(y % 2) return x * f(x, y - 1) % mod;
    ll p = f(x, y / 2);
    return p * p % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m;
    while(m--){
        cin >> b >> a;
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        ans += a * f(b, mod - 2) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}