#include <iostream>
#include <vector>

using namespace std;

int n, m, l = 0, s = 0, ans = 0;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, 0);

    for (int &a : arr) cin >> a;
    for (int i = 0;i < n;i++) {
        s += arr[i];
        while (s > m) s -= arr[l++];
        ans = max(ans, s);
    }
    cout << ans;
    return 0;
}