#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> tree;

vector<int> init(int start, int end, int nodeNum){
    if(start == end){
        tree[nodeNum].push_back(arr[start]);
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    tree[nodeNum] = init(start, mid, nodeNum * 2);
    vector<int> rc = init(mid + 1, end, nodeNum * 2 + 1);
    tree[nodeNum].insert(tree[nodeNum].end(), rc.begin(), rc.end());
    sort(tree[nodeNum].begin(), tree[nodeNum].end());
    return tree[nodeNum];
}

int find(int left, int right, int val, int start, int end, int nodeNum){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree[nodeNum].size() - distance(tree[nodeNum].begin(), upper_bound(tree[nodeNum].begin(), tree[nodeNum].end(), val));
    int mid = (start + end) / 2;
    return find(left, right, val, start, mid, nodeNum * 2) + find(left, right, val, mid + 1, end, nodeNum * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n + 1, 0);
    tree.assign(1 << ((int)ceil(log2(n)) + 1), vector<int>());
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    cin >> m;
    while(m--){
        int i, j, k;
        cin >> i >> j >> k;
        cout << find(i, j, k, 1, n, 1) << "\n";
    }
    return 0;
}