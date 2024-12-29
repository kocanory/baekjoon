#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> arr;
vector<pair<int, int>> tree;

pair<int, int> cmp(pair<int, int> a, pair<int, int> b){
    pair<int, int> res;
    int s;
    if(a.first > b.first){
        res.first = a.first;
        s = b.first;
    }
    else{
        res.first = b.first;
        s = a.first;
    }
    res.second = max(s, max(a.second, b.second));
    return res;
}

pair<int, int> init(int start, int end, int nodeNum){
    if(start == end) return tree[nodeNum] = {arr[start], 0};
    int mid = (start + end) / 2;
    return tree[nodeNum] = cmp(init(start, mid, nodeNum * 2), init(mid + 1, end, nodeNum * 2 + 1));
}

pair<int, int> update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] = {val, 0};
    int mid = (start + end) / 2;
    return tree[nodeNum] = cmp(update(start, mid, nodeNum * 2, target, val), update(mid + 1, end, nodeNum * 2 + 1, target, val));
}

pair<int, int> find(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return {0, 0};
    if(left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return cmp(find(left, right, start, mid, nodeNum * 2), find(left, right, mid + 1, end, nodeNum * 2 + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n + 1, 0);
    tree.assign(1 << ((int)ceil(log2(n)) + 1), pair<int, int>());
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    cin >> m;
    while(m--){
        int q;
        cin >> q;
        if(q == 1){
            int i, v;
            cin >> i >> v;
            update(1, n, 1, i, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            pair<int, int> ans = find(l, r, 1, n, 1);
            cout << ans.first + ans.second << "\n";
        }
    }
    return 0;
}