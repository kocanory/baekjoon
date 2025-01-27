#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, temp;
vector<bool> visited;
vector<vector<int>> ans;

void dfs(int idx) {
    if (temp.size() >= m) {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(arr[i]);
            dfs(i + 1);
            visited[i] = false;
            temp.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, 0);
    visited.assign(n, false);

    for (int i = 0; i < n; i++) cin >> arr[i];

    dfs(0);
    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        for (auto num : a)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}