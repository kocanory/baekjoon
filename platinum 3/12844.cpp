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

int update(int left, int right, int start, int end, int nodeNum, int val){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return tree[nodeNum];
    if(left <= start && end <= right){
        lazy[nodeNum] ^= val;
        lazy_update(start, end, nodeNum);
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(left, right, start, mid, nodeNum * 2, val) ^ update(left, right, mid + 1, end, nodeNum * 2 + 1, val);
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
    arr.assign(n + 1, 0);
    tree.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    lazy.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    cin >> m;
    while(m--){
        int a, i, j, k;
        cin >> a;
        if(a == 1){
            cin >> i >> j >> k;
            update(i + 1, j + 1, 1, n, 1, k);
        }
        else{
            cin >> i >> j;
            cout << find(i + 1, j + 1, 1, n, 1) << "\n";
        }
    }
    return 0;
}