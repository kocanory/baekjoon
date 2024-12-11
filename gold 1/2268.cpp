#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<long long> segTree;

long long update(int start, int end, int nodeNum, int target, int val) {
    if (target < start || target > end) return segTree[nodeNum];
    if (start == end) return segTree[nodeNum]  = val;
    int mid = (start + end) / 2;
    return segTree[nodeNum] = update(start, mid, nodeNum * 2, target, val) + update(mid + 1, end, nodeNum * 2 + 1, target, val);
}

long long subSum(int left, int right, int start, int end, int nodeNum) {
    if (end < left || start > right) return 0;
    if (left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    return subSum(left, right, start, mid, nodeNum * 2) + subSum(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    segTree.assign(1 << (int)ceil(log2(n)) + 1, 0);

    for (int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a) update(1, n, 1, b, c);
        else cout << subSum(min(b, c), max(b, c), 1, n, 1) << "\n";
    }

    return 0;
}