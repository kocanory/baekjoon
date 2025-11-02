#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, k;
vector<int> arr, check(1299709 + 1, true);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2;i <= 1299709; i++) {
        if (check[i]) {
            arr.push_back(i);
            for (int j = 2 * i;j <= 1299709; j += i)
                check[j] = false;
        }
    }

    cin >> t;
    while (t--) {
        cin >> k;
        int pos = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        cout << (arr[pos] == k ? 0 : arr[pos] - arr[pos - 1]) << "\n";
    }
    return 0;
}