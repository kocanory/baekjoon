#include <iostream>

using namespace std;

long long n, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1, j; i < n;i = j + 1) {
        j = (n - 1) / ((n - 1) / i);
        ans += ((n - 1) / i) * (j - i + 1);
    }
    cout << n + ans;
    return 0;
}