#include <iostream>
#include <vector>

using namespace std;

int n, res, val;
vector<int> arr, LtoR, RtoL;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    LtoR.assign(n, 0);
    RtoL.assign(n, 0);

    for (auto &a : arr) cin >> a;
    LtoR[0] = arr[0];
    RtoL[n - 1] = arr[n - 1];

    for (int i = 1;i < n;i++) LtoR[i] = gcd(LtoR[i - 1], arr[i]);
    for (int i = n - 2;i >= 0;i--) RtoL[i] = gcd(RtoL[i + 1], arr[i]);

    for (int i = 0;i < n;i++) {
        if (i == 0) {
            res = RtoL[1];
            val = arr[i];
        }
        else if (i == n - 1) {
            if (res < LtoR[n - 2]) {
                res = LtoR[n - 2];
                val = arr[i];
            }
        }
        else {
            if (res < gcd(LtoR[i - 1], RtoL[i + 1])) {
                res = gcd(LtoR[i - 1], RtoL[i + 1]);
                val = arr[i];
            }
        }
    }
    val % res == 0 ? cout << -1 : cout << res << " " << val;
    return 0;
}