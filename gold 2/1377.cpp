#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 0;
vector<pair<int, int>> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        arr.push_back({num, i});
    }
    stable_sort(arr.begin(), arr.end());

    for(int i = 0;i < n;i++){
        ans = max(ans, arr[i].second - i);
    }
    cout << ans + 1 << "\n";
    return 0;
}