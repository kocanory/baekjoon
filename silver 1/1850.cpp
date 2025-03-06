#include <iostream>
#include <numeric>

using namespace std;

long long a, b, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    n = gcd(a, b);
    while(n--) cout << 1;
    return 0;
}