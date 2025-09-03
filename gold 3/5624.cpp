#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, ans = 0;
vector<int> arr;
unordered_map<int, bool> check;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i;j++) {
            if (check[arr[i] - arr[j]]) {
                ans++;
                break;
            }
        }
        for (int j = 0;j <= i;j++)
            check[arr[i] + arr[j]] = true;
    }
    cout << ans;
    return 0;
}