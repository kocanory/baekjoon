#include <iostream>

using namespace std;

int n, l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    for (int i = l, L, N;i <= 100;i++) {
        L = (i - 1) * i / 2, N = n - L;
        if (N < 0) continue;
        if (N % i == 0) {
            for (int j = 0;j < i;j++)
                cout << N / i + j << " ";
            exit(0);
        }
    }
    cout << -1;
    return 0;
}