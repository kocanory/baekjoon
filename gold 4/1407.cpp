#include <iostream>

using namespace std;

typedef long long ll;
ll a, b;

ll calc(ll n){
    ll r = n;
    for(ll i = 2;i <= n;i *= 2)
        r += (n / i) * (i / 2);
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    cout << calc(b) - calc(a - 1);

    return 0;
}