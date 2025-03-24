#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, mod = 1000000007;
long long ans = 0, digit = 1;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    for(int i = 0;i < n;i++){
        long long sum = arr[i] * digit;
        ans = (ans + sum) % mod;
        digit = (digit << 1) % mod;
    }

    digit = 1;
    for(int i = n - 1;i >= 0;i--){
        long long sum = arr[i] * digit;
        ans = (ans - sum) % mod;
        if(ans < 0) ans += mod;
        digit = (digit << 1) % mod;
    }
    
    cout << ans << "\n";
    return 0;
}