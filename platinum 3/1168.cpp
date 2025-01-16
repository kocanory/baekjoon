#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, k, index = 1;
vector<int> tree;

int init(int start, int end, int nodeNum){
    if(start == end) return tree[nodeNum] = 1;
    int mid = (start + end) / 2;
    return tree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

int update(int start, int end, int nodeNum, int target){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] = 0;
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target) + update(mid + 1, end, nodeNum * 2 + 1, target);
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
    
    cin >> n >> k;
    tree.assign(1 << (int)ceil(log2(n)) + 1, 0);
    
    init(1, n, 1);
    
    cout << "<";
    for(int i = 0;i < n;i++){
        int size = n - i;
        index += k - 1;
        
        if(index % size == 0) index = size;
        else if(index > size) index %= size;
        
        int num = find(1, n, 1, index);
        update(1, n, 1, num);
        
        cout << num;
        if(i < n - 1) cout << ", ";
    }
    cout << ">";
    return 0;
}