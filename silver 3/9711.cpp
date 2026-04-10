#include <iostream>
#include <vector>

using namespace std;

int t, p, q;
vector<long long> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 1;i <= t;i++) {
        cin >> p >> q;
        arr.assign(p + 1, 0);
        arr[1] = 1 % q;
        for (int j = 2;j <= p;j++)
            arr[j] = (arr[j - 1] + arr[j - 2]) % q;
        cout << "Case #" << i << ": " << arr[p] << "\n";
    }
    return 0;
}