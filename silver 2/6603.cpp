#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> arr, ans;

void dfs(int idx) {
    if (ans.size() == 6) {
        for (auto &a : ans)
            cout << a << " ";
        cout << "\n";
        return;
    }
    for (int i = idx;i < k;i++) {
        ans.push_back(arr[i]);
        dfs(i + 1);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> k;
        if (!k) break;
        arr.assign(k, 0);
        for (int &a : arr) cin >> a;
        dfs(0);
        cout << "\n";
    }
    return 0;
}