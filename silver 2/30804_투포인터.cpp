#include <iostream>
#include <vector>

using namespace std;

int n, t = 0, st = 0, en = 0, ans = 1;
vector<int> arr, cnt(10);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cnt[arr[st]]++;
    t++;
    while (st <= en) {
        while (en < n) {
            en++;
            if (en >= n) break;
            if (!cnt[arr[en]]) t++;
            cnt[arr[en]]++;
            if (t > 2) {
                cnt[arr[en]]--;
                if (!cnt[arr[en]]) t--;
                en--;
                ans = max(ans, en - st + 1);
                break;
            }
            ans = max(ans, en - st + 1);
        }
        cnt[arr[st]]--;
        if (!cnt[arr[st]]) t--;
        st++;
    }
    cout << ans << "\n";
}