#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> arr, tree, lazy;

int init(int start, int end, int nodeNum){
    if(start == end) return tree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return tree[nodeNum] = init(start, mid, nodeNum * 2) ^ init(mid + 1, end, nodeNum * 2 + 1);
}

void lazy_update(int start, int end, int nodeNum){
    if(lazy[nodeNum]){
        if((end - start + 1) % 2) tree[nodeNum] ^= lazy[nodeNum];
        if(start != end){
            lazy[nodeNum * 2] ^= lazy[nodeNum];
            lazy[nodeNum * 2 + 1] ^= lazy[nodeNum];
        }
        lazy[nodeNum] = 0;
    }
}

int update(int left, int right, int val, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return tree[nodeNum];
    if(left <= start && end <= right){
        lazy[nodeNum] += val;
        lazy_update(start, end, nodeNum);
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(left, right, val, start, mid, nodeNum * 2) ^ update(left, right, val, mid + 1, end, nodeNum * 2 + 1);
}

int find(int left, int right, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) ^ find(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    tree.assign(1 << (int)ceil(log2(n)) + 1, 0);
    lazy.assign(1 << (int)ceil(log2(n)) + 1, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];
    init(0, n - 1, 1);

    cin >> m;
    while(m--){
        int t, a, b, c;
        cin >> t >> a;
        if(t == 1){
            cin >> b >> c;
            update(a, b, c, 0, n - 1, 1);
        }
        else cout << find(a, a, 0, n - 1, 1) << "\n";
    }

    return 0;
}