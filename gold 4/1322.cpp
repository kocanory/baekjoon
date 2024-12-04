#include <iostream>

using namespace std;

long long n, k, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i = 0;k > 0;i++){
        if(n & (1LL << i)) continue;
        if(k & 1) ans |= (1LL << i);
        k >>= 1;
    }
    cout << ans << "\n";
    return 0;
}