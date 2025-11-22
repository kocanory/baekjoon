#include <iostream>
#include <vector>

using namespace std;

int n, q, a, b;
vector<int> arr, check;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, 0);
    check.assign(n + 1, 0);

    for (int i = 1;i <= n;i++) cin >> arr[i];

    for (int i = 2;i <= n;i++) {
        if (arr[i - 1] > arr[i]) check[i] = 1;
        check[i] += check[i - 1];
    }

    cin >> q;
    while (q--) {
        cin >> a >> b;
        cout << check[b] - check[a] << "\n";
    }
    return 0;
}