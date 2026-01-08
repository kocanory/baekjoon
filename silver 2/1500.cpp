#include <iostream>
#include <cmath>

using namespace std;

int s, k, a, b;
unsigned long long ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> k;
    a = s / k, b = s % k;
    ans = pow(a, k - b) * pow(a + 1, b);
    cout << ans;
    return 0;
}