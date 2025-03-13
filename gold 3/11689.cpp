#include <iostream>

using namespace std;

long long n, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    ans = n;
    
    for(long long i = 2;i * i <= n;i++){
        if(n % i == 0){
            ans -= ans / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ans -= ans / n;
    cout << ans << "\n";
    return 0;
}