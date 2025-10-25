#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> mat;

long long t, num;

mat operator* (mat a, mat b) {
    mat res = {{0, 0}, {0, 0}};
    for (int i = 0;i < 2;i++)
        for (int j = 0;j < 2;j++) {
            for (int k = 0;k < 2;k++)
                res[i][j] += (a[i][k] * b[k][j]) % (int)1e9;
            res[i][j] %= (int)1e9;
        }
    return res;
}

mat pow(mat x, long long n) {
    if (n == 1) return x;
    mat res = pow(x, n / 2);
    return n % 2 ? res * res * x : res * res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> num;
        cout << pow({{1, 1}, {1, 0}}, num)[0][1] << "\n";
    }

    return 0;
}