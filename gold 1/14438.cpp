#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> arr, segTree;

int init(int start, int end, int nodeNum) {
    if (start == end) return segTree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return segTree[nodeNum] = min(init(start, mid, nodeNum * 2), init(mid + 1, end, nodeNum * 2 + 1));
}

int update(int start, int end, int nodeNum, int target, int val) {
    if (target < start || target > end) return segTree[nodeNum];
    if (start == end) return segTree[nodeNum] = val;
    int mid = (start + end) / 2;
    return segTree[nodeNum] = min(update(start, mid, nodeNum * 2, target, val), update(mid + 1, end, nodeNum * 2 + 1, target, val));
}

int find(int left, int right, int start, int end, int nodeNum) {
    if (end < left || start > right) return 1e9;
    if (left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    return min(find(left, right, start, mid, nodeNum * 2), find(left, right, mid + 1, end, nodeNum * 2 + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, 0);
    segTree.assign(1 << (int)ceil(log2(n)) + 1, 0);

    for (int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);

    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) update(1, n, 1, b, c);
        else cout << find(b, c, 1, n, 1) << "\n";
    }
    return 0;
}