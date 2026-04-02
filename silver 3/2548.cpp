#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cout << (n % 2 ? arr[n / 2] : arr[n / 2 - 1]);

    return 0;
}