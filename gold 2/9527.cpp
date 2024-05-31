#include <iostream>
#include <vector>

using namespace std;

long long a, b;
vector<long long> power2(64);

long long check(long long n){
    long long ret = n & 1;
    
    for(int i = 63;i > 0;i--){
        if(n & (1LL << i)){
            ret += power2[i - 1] + (n - (1LL << i) + 1);
            n -= 1LL << i;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b;
    
    power2[0] = 1;
    for(int i = 1;i < 64;i++) power2[i] = power2[i - 1] * 2 + (1LL << i);
    cout << check(b) - check(a - 1) << "\n";
    return 0;
}