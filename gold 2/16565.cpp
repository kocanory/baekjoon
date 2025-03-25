#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0, mod = 10007;
vector comb(53, vector<int>(53));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0;i <= 52;i++) comb[i][0] = 1;
    
    for(int i = 1;i <= 52;i++)
        for(int j = 1;j <= 52;j++)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
    
    cin >> n;
    
    for(int i = 1;i <= 13 && n - 4 * i >= 0;i++){
        if(i % 2) ans = (ans + comb[13][i] * comb[52 - 4 * i][n - 4 * i]) % mod;
        else ans = (ans - comb[13][i] * comb[52 - 4 * i][n - 4 * i] % mod + mod) % mod;
    }
    cout << ans << "\n";
    return 0;
}