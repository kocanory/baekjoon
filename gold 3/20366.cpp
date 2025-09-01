#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int n;
vector<int> arr;
ll ans = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    for (int i = 0;i < n - 3 && ans > 0;i++) {
        for (int j = i + 3; j < n;j++) {
            ll elsa = arr[i] + arr[j];
            int s = i + 1, e = j - 1;
            while (s < e && ans != 0) {
                ll anna = arr[s] + arr[e];
                ans = min(ans, abs(elsa - anna));

                if (elsa >= anna) s++;
                else e--;
            }
        }
    }
    cout << ans;
    return 0;
}