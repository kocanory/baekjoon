#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

ll a, b, ans = 0;
ll MOD = 1000000000;
matrix n = {{1, 1}, {1, 0}};

matrix operator*(matrix &n1, matrix &n2){
    int size = n1.size();
    matrix ret(2, vector<ll>(2));
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            for(int k = 0;k < size;k++)
            {
                ret[i][j] += (n1[i][k] * n2[k][j]);
            }
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

matrix calc(matrix n1, long long count){
    matrix ret = {{1, 0}, {0, 1}};
    while(count){
        if(count % 2) ret = ret * n1;
        n1 = n1 * n1;
        count /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    matrix n1 = calc(n, b + 2), n2 = calc(n, (a - 1) + 2);
    ans = ((n1[0][1] - 1) - (n2[0][1] - 1) + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}