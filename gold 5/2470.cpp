#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 3 * 1e9;
vector<int> arr, answer(2);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    for(auto &a : arr){
        int index = lower_bound(arr.begin(), arr.end(), -a) - arr.begin();

        for(int i = index;i >= index - 1;i--) {
            if(a == arr[i] || i < 0 || i >= n) continue;
            if (abs(a + arr[i]) < abs(sum)) {
                answer[0] = min(a, arr[i]), answer[1] = max(a, arr[i]);
                sum = a + arr[i];
            }
        }
    }

    cout << answer[0] << " " << answer[1] << "\n";
    return 0;
}