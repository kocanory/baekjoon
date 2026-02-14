#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, k, n, i, j, val, ans, diff;
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
        sort(b.begin(), b.end());
        ans = 0, diff = 1e9;
        i = 0, j = b.size() - 1;

        while (i < a.size() && 0 <= j) {
            val = a[i] + b[j];
            if (abs(val - k) < diff) {
                diff = abs(val - k);
                ans = val;
            }
            else if (abs(val - k) == diff)
                ans = min(ans, val);

            if (val - k > 0) j--;
            else if (val - k < 0) i++;
            else break;
        }
        
        cout << ans << "\n";
    }
}