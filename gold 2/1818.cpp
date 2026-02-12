#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, lis;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int a : arr) {
        if (lis.empty() || lis.back() < a) lis.push_back(a);
        else {
            auto pos = lower_bound(lis.begin(), lis.end(), a);
            *pos = a;
        }
    }
    cout << n - lis.size();
}