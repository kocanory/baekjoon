#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a, b, idx, lis;
vector<pair<int, int>> back;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    idx.assign(n + 1, 0);

    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) {
        cin >> b[i];
        idx[b[i]] = i;
    }

    for (auto num : a) {
        int pos = distance(lis.begin(), lower_bound(lis.begin(), lis.end(), idx[num]));
        if (pos == lis.size()) lis.push_back(idx[num]);
        else lis[pos] = idx[num];
        back.push_back({pos, num});
    }

    int size = lis.size();
    cout << size << "\n";
    for (int i = n - 1;i >= 0;i--) {
        if (size - 1 == back[i].first) {
            lis[size - 1] = back[i].second;
            size--;
        }
    }
    sort(lis.begin(), lis.end());
    for (auto l : lis)
        cout << l << " ";
    return 0;
}