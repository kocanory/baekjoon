#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, a, b;
vector<int> tree;

int update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] += val;
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target, val) + update(mid + 1, end, nodeNum * 2 + 1, target, val);
}

int find(int start, int end, int nodeNum, int idx){
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(tree[nodeNum * 2] >= idx) return find(start, mid, nodeNum * 2, idx);
    return find(mid + 1, end, nodeNum * 2 + 1, idx - tree[nodeNum * 2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    tree.assign(1 << ((int)ceil(log2(2000000)) + 1), 0);

    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a == 1) update(1, 2000000, 1, b, 1);
        else {
            int val = find(1, 2000000, 1, b);
            cout << val << "\n";
            update(1, 2000000, 1, val, -1);
        }
    }

    return 0;
}