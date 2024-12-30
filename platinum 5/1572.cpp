#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, k, Max = 65537;
long long ans = 0;
vector<int> arr, tree;

int update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] += val;
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target, val) + update(mid + 1, end, nodeNum * 2 + 1, target, val);
}

int find(int start, int end, int nodeNum, int cnt){
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(tree[nodeNum * 2] >= cnt) return find(start, mid, nodeNum * 2, cnt);
    return find(mid + 1, end, nodeNum * 2 + 1, cnt - tree[nodeNum * 2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    arr.assign(n + 1, 0);
    tree.assign(1 << ((int)ceil(log2(Max)) + 1), 0);

    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        update(0, Max, 1, arr[i], 1);
        if(i >= k){
            ans += find(0, Max, 1, (k + 1) / 2);
            update(0, Max, 1, arr[i - k + 1], -1);
        }
    }
    cout << ans << "\n";
    return 0;
}