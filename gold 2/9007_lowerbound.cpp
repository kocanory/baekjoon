#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, k, n, ans, diff;
vector<vector<int>> arr;
vector<int> a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> k >> n;
        arr.assign(4, vector(n, 0));
        a.clear();
        b.clear();

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                a.push_back(arr[0][i] + arr[1][j]);
                b.push_back(arr[2][i] + arr[3][j]);
            }
        }
        sort(a.begin(), a.end());
        ans = 0, diff = 1e9;

        for (auto num : b) {
            int pos = lower_bound(a.begin(), a.end(), k - num) - a.begin();

            if (pos == a.size()) {
                if (abs(a[pos - 1] + num - k) < diff) {
                    diff = abs(a[pos - 1] + num - k);
                    ans = a[pos - 1] + num;
                }
            }
            else {
                if (abs(a[pos] + num - k) < diff) {
                    diff = abs(a[pos] + num - k);
                    ans = a[pos] + num;
                }
                if (pos >= 1) {
                    if (abs(a[pos - 1] + num - k) <= diff) {
                        diff = abs(a[pos - 1] + num - k);
                        ans = a[pos - 1] + num;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}