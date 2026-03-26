#include <iostream>
#include <vector>

using namespace std;

int n, m, s, e;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, 0);

    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << arr[e] - arr[s - 1] << "\n";
    }

    return 0;
}