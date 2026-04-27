#include <iostream>
#include <vector>

using namespace std;

int n, a, b, k, s = 0, ans = 0;
vector<int> arr(1000001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    while (n--) {
        cin >> a >> b;
        arr[b] = a;
    }

    k = 2 * k + 1;

    for (int i = 0;i <= 1000000;i++) {
        if (i >= k) s -= arr[i - k];
        s += arr[i];
        ans = max(ans, s);
    }
    cout << ans;
    return 0;
}