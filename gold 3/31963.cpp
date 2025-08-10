#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
long long ans = 0;
vector<int> arr, cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    cnt.assign(n, 0);

    for (int i = 0;i < n;i++) cin >> arr[i];

    for (int i = 1;i < n;i++) {
        int val = ceil(log2(arr[i - 1] / (double)arr[i])) + cnt[i - 1];
        if (val > 0) {
            ans += val;
            cnt[i] = val;
        }
    }
    cout << ans;
}