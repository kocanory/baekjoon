#include <iostream>
#include <vector>

using namespace std;

int n, idx = 0, ans = 0;
vector<int> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] -= num;
    }

    while (idx < n) {
        if (arr[idx] != 0) {
            int min = arr[idx];
            for (int i = idx + 1; i < n + 1; i++) {
                if (i < n && arr[idx] * arr[i] > 0) {
                    if (abs(arr[i]) < abs(min))
                        min = arr[i];
                }
                else {
                    ans += abs(min);
                    for (int j = idx;j < i;j++)
                        arr[j] -= min;
                    break;
                }
            }
        }
        else idx++;
    }
    cout << ans;
}