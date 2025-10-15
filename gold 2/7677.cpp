#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> mat;
int t;

mat operator * (mat a, mat b) {
    int size = a.size();
    mat res(size, vector(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                res[i][j] += a[i][k] * b[k][j] % 10000;
    return res;
}

mat pow(mat x, int n) {
    if (n == 1) return x;
    mat res = pow(x, n / 2);
    if (n % 2) return res * res * x;
    return res * res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> t;
        if (t == -1) break;
        if (t == 0) cout << 0 << "\n";
        else {
            mat x = {{1, 1}, {1, 0}}, res = pow(x, t);
            cout << res[0][1] % 10000 << "\n";
        }
    }

    return 0;
}