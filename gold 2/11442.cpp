#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1000000007;
ll n;

matrix m = {{1, 1}, {1, 0}};

matrix operator*(matrix &a, matrix &b){
    int size = a.size();
    matrix ret(size, vector<ll>(size));
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            for(int k = 0;k < size;k++)
                ret[i][j] += (a[i][k] * b[k][j]);
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

ll calc(ll count){
    matrix ans = {{1, 0}, {0, 1}};
    while(count){
        if(count % 2) ans = ans * m;
        m = m * m;
        count >>= 1;
    }
    return ans[0][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    if(n % 2 == 0) n--;
    ll ans = calc((n - 1) + 2);
    cout << (ans - 1) + 1 << "\n";
    return 0;
}