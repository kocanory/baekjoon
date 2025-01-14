#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, cnt = 0;
vector<int> st, en, tree, lazy;
vector<vector<int>> arr;

int init(int start, int end, int nodeNum) {
    if (start == end) return tree[nodeNum] = 1;
    int mid = (start + end) / 2;
    return tree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

void dfs(int now) {
    st[now] = ++cnt;
    for (auto next : arr[now]) dfs(next);
    en[now] = cnt;
}

void lazy_update(int start, int end, int nodeNum) {
    if (lazy[nodeNum] != -1) {
        tree[nodeNum] = (end - start + 1) * lazy[nodeNum];
        if (start != end) {
            lazy[nodeNum * 2] = lazy[nodeNum];
            lazy[nodeNum * 2 + 1] = lazy[nodeNum];
        }
        lazy[nodeNum] = -1;
    }
}

int update(int left, int right, int val, int start, int end, int nodeNum) {
    lazy_update(start, end, nodeNum);
    if (end < left || start > right) return tree[nodeNum];
    if (left <= start && end <= right) {
        lazy[nodeNum] = val;
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

    cin >> n;
    st.assign(n + 1, 0);
    en.assign(n + 1, 0);
    arr.assign(n + 1, vector<int>());
    tree.assign(1 << (int)ceil(log2(n)) + 1, 1);
    lazy.assign(1 << (int)ceil(log2(n)) + 1, -1);

    for (int i = 1;i <= n;i++) {
        int p;
        cin >> p;
        if (i > 1) arr[p].push_back(i);
    }

    dfs(1);
    init(1, n, 1);
    
    cin >> m;
    while (m--) {
        int q, i;
        cin >> q >> i;
        if (q == 1) update(st[i] + 1, en[i], 1, 1, n, 1);
        else if (q == 2) update(st[i] + 1, en[i], 0, 1, n, 1);
        else cout << find(st[i] + 1, en[i], 1, n, 1) << '\n';
    }
    return 0;
}