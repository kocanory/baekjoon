#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long maxTime = 0;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(m, 0);


    for(int i = 0 ;i < m;i++) {
        cin >> arr[i];
        maxTime = max(maxTime, (long long)arr[i]);
    }

    if(n <= m){
        cout << n << "\n";
        return 0;
    }

    long long left = 0, right = maxTime * n;
    while(left <= right){
        long long mid = (left + right) / 2, sum = m;
        for(auto &a : arr) sum += (mid / a);
        if(sum >= n) right = mid - 1;
        else left = mid + 1;
    }

    long long sum = m;
    for(auto &a : arr) sum += ((left - 1) / a);

    int k = n - sum, ans = 0;

    while(k){
        if(left % arr[ans] == 0) k--;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}