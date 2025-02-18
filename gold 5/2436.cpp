#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

int n, m;
pair<int, int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    int num = m / n;
    
    for(int i = 1; i <= sqrt(num);i++){
        if(num % i == 0){
            int a = i, b = num / i;
            if(gcd(a, b) == 1)
                ans = {n * a, n * b};
        }
    }
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}