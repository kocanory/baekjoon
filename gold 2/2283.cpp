#include <iostream>
#include <vector>

using namespace std;

int n, k, a, b, l = 0, r = 0, sum = 0;
vector<int> arr(1000001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[a]++;
        arr[b]--;
    }

    for (int i = 1;i <= 1000000;i++) arr[i] += arr[i - 1];

    while (0 <= l && l <= r && r <= 1000000) {
        if (sum == k) {
            cout << l << " " << r;
            exit(0);
        }
        if (sum > k) {
            sum -= arr[l++];
        }
        else
            sum += arr[r++];
    }
    cout << 0 << " " << 0;
    return 0;
}