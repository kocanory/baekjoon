#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll n, p, q, x, y;
unordered_map<ll, ll> dp;

ll recursive(ll i, ll p, ll q, ll x, ll y){
    i = max((ll)0, i);
    
    if(dp[i] != 0) return dp[i];
    return dp[i] = recursive(i / p - x, p, q, x, y) + recursive(i / q - y, p, q, x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> p >> q >> x >> y;
    dp[0] = 1;
    
    cout << recursive(n, p, q, x, y);

    return 0;
}