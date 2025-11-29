#include <iostream>
#include <vector>

using namespace std;

int n, preSum = 0, sum = 0;
long long cnt = 0, n1 = 0, n2 = 0, n3 = 0;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        preSum += arr[i];
    }

    if (preSum % 4) {
        cout << 0;
        exit(0);
    }

    preSum /= 4;
    for (int i = 0;i < n - 1;i++) {
        sum += arr[i];
        if (!preSum) {
            if (!sum)
                cnt++;
        }
        else {
            if (sum % preSum == 0) {
                if (sum / preSum == 1) n1++;
                else if (sum / preSum == 2) n2 += n1;
                else if (sum / preSum == 3) n3 += n2;
                if (sum) cnt++;
            }
        }
    }

    if (cnt < 3) {
        cout << 0;
        exit(0);
    }
    if (!preSum) cout << (cnt * (cnt - 1) * (cnt - 2) / 6);
    else cout << n3;
    return 0;
}