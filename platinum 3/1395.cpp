#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> tree, lazy;

void lazy_update(int start, int end, int nodeNum){
    if(lazy[nodeNum]){
        tree[nodeNum] = (end - start + 1) - tree[nodeNum];
        if(start != end){
            lazy[nodeNum * 2] = !lazy[nodeNum * 2];
            lazy[nodeNum * 2 + 1] = !lazy[nodeNum * 2 + 1];
        }
        lazy[nodeNum] = 0;
    }
}

int update(int left, int right, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return tree[nodeNum];
    if(left <= start && end <= right){
        tree[nodeNum] = (end - start + 1) - tree[nodeNum];
        if(start != end){
            lazy[nodeNum * 2] = !lazy[nodeNum * 2];
            lazy[nodeNum * 2 + 1] = !lazy[nodeNum * 2 + 1];
        }
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(left, right, start, mid, nodeNum * 2) + update(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int find(int left, int right, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) + find(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    tree.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    lazy.assign(1 << ((int)ceil(log2(n)) + 1), 0);

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a) cout << find(b, c, 1, n, 1) << "\n";
        else update(b, c, 1, n, 1);
    }
    return 0;
}