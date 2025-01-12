#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, cnt = 0;
vector<int> st, en, lazy, tree;
vector<vector<int>> arr;

void dfs(int now) {
    st[now] = ++cnt;
    for (auto next : arr[now]) dfs(next);
    en[now] = cnt;
}

void lazy_update(int start, int end, int nodeNum) {
    if (lazy[nodeNum]) {
        tree[nodeNum] += (start - end + 1) * lazy[nodeNum];
        if (start != end) {
            lazy[nodeNum * 2] += lazy[nodeNum];
            lazy[nodeNum * 2 + 1] += lazy[nodeNum];
        }
        lazy[nodeNum] = 0;
    }
}

int update(int left, int right, int val, int start, int end, int nodeNum) {
    lazy_update(start, end, nodeNum);
    if (end < left || start > right) return tree[nodeNum];
    if (left <= start && end <= right) {
        lazy[nodeNum] += val;
        lazy_update(start, end, nodeNum);
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(left, right, val, start, mid, nodeNum * 2) + update(left, right, val, mid + 1, end, nodeNum * 2 + 1);
}

int find(int left, int right, int start, int end, int nodeNum) {
    lazy_update(start, end, nodeNum);
    if (end < left || start > right) return 0;
    if (left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) + find(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n + 1, vector<int>());
    tree.assign(1 << (int)ceil(log2(n)) + 1, 0);
    lazy.assign(1 << (int)ceil(log2(n)) + 1, 0);
    st.assign(n + 1, 0);
    en.assign(n + 1, 0);

    for (int i = 1;i <= n;i++){
        int p;
        cin >> p;
        if (i > 1) arr[p].push_back(i);
    }

    dfs(1);

    while (m--) {
        int q, i, w;
        cin >> q >> i;
        if (q == 1) {
            cin >> w;
            update(st[i], st[i], w, 1, n, 1);
        }
        else cout << find(st[i], en[i], 1, n, 1) << "\n";
    }
    return 0;
}