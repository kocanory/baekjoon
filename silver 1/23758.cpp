#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, ans;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int i = 0;i <n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int mid = (n + 1) / 2;

    for (int i = 0;i < mid;i++)
        ans += floor(log2(arr[i]));
    cout << ans + 1;
    return 0;
}