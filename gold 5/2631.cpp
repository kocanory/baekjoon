#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
    for(auto &a : arr) {
        if(ans.empty() || ans.back() < a) ans.push_back(a);
        else {
            auto pos = lower_bound(ans.begin(), ans.end(), a);
            *pos = a;
        }
    }
    cout << n - ans.size() << "\n";
    return 0;
}