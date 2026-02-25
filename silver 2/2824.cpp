#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool flag = false;
long long ans = 1, mod = 1e9;
vector<int> A, B;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    A.assign(n, 0);
    for (int i = 0;i < n;i++) cin >> A[i];

    cin >> m;
    B.assign(m, 0);
    for (int i = 0;i < m;i++) cin >> B[i];

    for (int i = 0;i < n;i++) {
        for (int j = 0, gc;j < m;j++) {
            gc = gcd(A[i], B[j]);

            ans *= gc;
            A[i] /= gc;
            B[j] /= gc;

            if (ans >= mod) {
                ans %= mod;
                flag = true;
            }
        }
    }

    if (flag) {
        string str = to_string(ans);
        cout << string(9 - str.size(), '0') + str;
    }
    else cout << ans;
    return 0;
}