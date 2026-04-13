#include <iostream>
#include <vector>

using namespace std;

int t, n, nxt, ans;
vector<int> arr, check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n;
        arr.assign(n + 1, 0);
        check = arr;

        for (int i = 1;i <= n;i++) cin >> arr[i];
        ans = 0;

        for (int i = 1;i <= n;i++) {
            if (!check[i]) {
                ans++;
                check[i] = true;
                nxt = arr[i];
                while (!check[nxt]) {
                    check[nxt] = true;
                    nxt = arr[nxt];
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}