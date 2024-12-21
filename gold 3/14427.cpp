#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> arr;
vector<pair<int, int>> segTree;

pair<int, int> init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = {arr[start], start};
    int mid = (start + end) / 2;
    return segTree[nodeNum] = min(init(start, mid, nodeNum * 2), init(mid + 1, end, nodeNum * 2 + 1));
}

pair<int, int> update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return segTree[nodeNum];
    if(start == end) return segTree[nodeNum] = {val, start};
    int mid = (start + end) / 2;
    return segTree[nodeNum] = min(update(start, mid, nodeNum * 2, target, val), update(mid + 1, end, nodeNum * 2 + 1, target, val));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, 0);
    segTree.assign(1 << ((int)ceil(log2(n)) + 1), pair<int, int>());
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    cin >> m;
    while(m--){
        int c;
        cin >> c;
        if(c == 1){
            int i, v;
            cin >> i >> v;
            update(1, n, 1, i, v);
        }
        else cout << segTree[1].second << "\n";
    }
    return 0;
}