#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
vector<int> arr;

bool checkAllZero(){
    for(auto &a : arr)
        if(a != 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    if(checkAllZero()){
        cout << n << "\n";
        return 0;
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j) continue;
            int index = lower_bound(arr.begin(), arr.end(), arr[i] - arr[j]) - arr.begin();
            if(index == i || index == j) continue;
            if(arr[i] == arr[j] + arr[index]){
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}