#include <iostream>
#include <vector>

using namespace std;

int n, s, ans = 0;
vector<int> arr;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    arr.assign(n, 0);

    for (int &a : arr) {
        cin >> a;
        ans = (ans == 0 ? abs(a - s) : gcd(ans, abs(a - s)));
    }

    cout << ans;
}