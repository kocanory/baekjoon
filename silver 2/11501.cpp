#include <iostream>
#include <vector>

using namespace std;

int t, n, m;
long long ans;
vector<int> arr;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--) {
        cin >> n;
        arr.assign(n, 0);
        for(int &a : arr) cin >> a;

        m = ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            m = max(m, arr[i]);
            ans += m - arr[i];
        }
        cout << ans << "\n";
    }
}