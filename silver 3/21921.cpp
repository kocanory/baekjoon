#include <iostream>
#include <vector>

using namespace std;

int n, x, Max = 0, cnt = 1;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    Max = arr[x] - arr[0];

    for (int i = x + 1;i <= n; i++) {
        if (Max < arr[i] - arr[i - x]) {
            Max = arr[i] - arr[i - x];
            cnt = 1;
        }
        else if (Max == arr[i] - arr[i - x])
            cnt++;
    }

    if (Max == 0)
        cout << "SAD";
    else
        cout << Max << "\n" << cnt;
    return 0;
}