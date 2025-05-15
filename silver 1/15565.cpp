#include <iostream>
#include <vector>

using namespace std;

int n, k, l = 0, ans = 1e6, cnt = 0;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0;i < n;i++) {
        if (arr[i] == 1) cnt++;
        while (cnt >= k) {
            ans = min(ans, i - l + 1);
            if (arr[l] == 1) cnt--;
            l++;
        }
    }

    cout << (ans == 1e6 ? -1 : ans);
    return 0;
}