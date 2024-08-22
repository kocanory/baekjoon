#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, ans, index;

void backtrack(int idx, int seq) {
    if(idx < 0) return;
    if(seq == index[idx]) {
        backtrack(idx - 1, seq - 1);
        cout << arr[idx] << " ";
    }
    else backtrack(idx - 1, seq);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(auto &a : arr) {
        if(ans.empty() || ans.back() < a) {
            ans.push_back(a);
            index.push_back(ans.size() - 1);
        }
        else {
            auto pos = lower_bound(ans.begin(), ans.end(), a);
            *pos = a;
            index.push_back(pos - ans.begin());
        }
    }
    cout << ans.size() << "\n";
    backtrack(arr.size() - 1, ans.size() - 1);
    return 0;
}