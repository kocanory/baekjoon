#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, k, a;
vector<int> arr, lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 1;i <= t;i++) {
        cin >> n >> k;
        arr.assign(n, 0);
        lis.clear();

        for (int j = 0;j < n;j++) {
            cin >> a;
            if (lis.empty() || lis.back() < a) lis.push_back(a);
            else {
                auto pos = lower_bound(lis.begin(), lis.end(), a);
                *pos = a;
            }
        }
        cout << "Case #" << i << "\n" << (lis.size() >= k ? 1 : 0) << "\n";
    }
    return 0;
}