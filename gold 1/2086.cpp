#include <iostream>
#include <vector>
#define MOD 1000000000

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

ll a, b, ans;
matrix m = {{1, 1}, {1, 0}};

matrix operator *(matrix &n1, matrix &n2){
    int size = n1.size();
    matrix ret(size, vector<ll>(size));
    for(int i = 0;i < size;i++){
        for(int j = 0;j <size;j++){
            for(int k = 0;k < size;k++)
                ret[i][j] += (n1[i][k] * n2[k][j]);
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

ll calc(matrix n1, ll count){
    matrix ans = {{1, 0}, {0, 1}};
    while(count){
        if(count % 2) ans = ans * n1;
        n1 = n1 * n1;
        count >>= 1;
    }
    return ans[0][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    ans = (calc(m, b + 2) - calc(m, (a - 1) + 2) + MOD) % MOD;
    cout << ans << "\n";

    return 0;
}