#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, temp;
vector<vector<int>> ans;

void dfs(int idx) {
    if (temp.size() >= m) {
        ans.push_back(temp);
        return;
    }
    for (int i = idx;i < arr.size();i++) {
        temp.push_back(arr[i]);
        dfs(i);
        temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, 0);

    for (int i = 0;i < n;i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    dfs(0);

    for (auto a : ans) {
        for (auto num : a)
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}