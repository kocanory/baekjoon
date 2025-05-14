#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, ans;
vector<string> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, "");

    for (int i = 0;i < n;i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    ans = n;
    for (int i = 0;i < n;i++)
        for (int j = i + 1;j < n;j++)
            if (arr[i] == arr[j].substr(0, arr[i].length())) {
                ans--;
                break;
            }
    cout << ans;
    return 0;
}