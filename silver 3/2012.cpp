#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long ans = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0, num;i < n;i++) {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0;i < n;i++)
        ans += abs(arr[i] - 1 - i);

    cout << ans;
    return 0;
}