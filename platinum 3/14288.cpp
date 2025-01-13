#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, cnt = 0;
bool flag = false;
vector<int> st, en;
vector<vector<int>> arr, lazy, tree;

void dfs(int now) {
    st[now] = ++cnt;
    for (auto next : arr[now]) dfs(next);
    en[now] = cnt;
}

void lazy_update(bool flag, int start, int end, int nodeNum) {
    if (lazy[flag][nodeNum]) {
        tree[flag][nodeNum] += (end - start + 1) * lazy[flag][nodeNum];
        if (start != end) {
            lazy[flag][nodeNum * 2] += lazy[flag][nodeNum];
            lazy[flag][nodeNum * 2 + 1] += lazy[flag][nodeNum];
        }
        lazy[flag][nodeNum] = 0;
    }
}

int update(int left, int right, int val, int start, int end, int nodeNum, bool flag) {
    lazy_update(flag, start, end, nodeNum);
    if (end < left || start > right) return tree[flag][nodeNum];
    if (left <= start && end <= right) {
        lazy[flag][nodeNum] += val;
        lazy_update(flag, start, end, nodeNum);
        return tree[flag][nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[flag][nodeNum] = update(left, right, val, start, mid, nodeNum * 2, flag) + update(left, right, val, mid + 1, end, nodeNum * 2 + 1, flag);
}

int find(int left, int right, int start, int end, int nodeNum, bool flag) {
    lazy_update(flag, start, end, nodeNum);
    if (end < left || start > right) return 0;
    if (left <= start && end <= right) return tree[flag][nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2, flag) + find(left, right, mid + 1, end, nodeNum * 2 + 1, flag);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    st.assign(n + 1, 0);
    en.assign(n + 1, 0);
    arr.assign(n + 1, vector<int>());
    lazy.assign(2, vector<int>(1 << (int)ceil(log2(n)) + 1, 0));
    tree.assign(2, vector<int>(1 << (int)ceil(log2(n)) + 1, 0));

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (i > 1) arr[p].push_back(i);
    }

    dfs(1);

    while (m--) {
        int q, i, w;
        cin >> q;
        if (q == 1) {
            cin >> i >> w;
            if (flag) update(st[i], st[i], w, 1, n, 1, flag);
            else update(st[i], en[i], w, 1, n, 1, flag);
        }
        else if (q == 2) {
            cin >> i;
            cout << find(st[i], st[i], 1, n, 1, 0) + find(st[i], en[i], 1, n, 1, 1) << "\n";
        }
        else flag = !flag;

    }
    return 0;
}