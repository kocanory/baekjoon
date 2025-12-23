#include <iostream>
#include <vector>

using namespace std;

int n, j;
vector<int> arr, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    ans = arr;

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        j = 0;

        while (arr[i] || ans[j]) {
            if (!ans[j])
                arr[i]--;
            j++;
        }

        ans[j] = i + 1;
    }

    for (int a : ans) cout << a << " ";
    return 0;
}