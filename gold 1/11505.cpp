#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;
vector<long long> arr, segTree;

long long init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return segTree[nodeNum] = init(start, mid, nodeNum * 2) * init(mid + 1, end, nodeNum * 2 + 1) % 1000000007;
}

long long update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return segTree[nodeNum];
    if(start == end) return segTree[nodeNum] = val;
    int mid = (start + end) / 2;
    return segTree[nodeNum] = update(start, mid, nodeNum * 2, target, val) * update(mid + 1, end, nodeNum * 2 + 1, target, val) % 1000000007;
}

long long subMul(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return 1;
    if(left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    return subMul(left, right, start, mid, nodeNum * 2) * subMul(left, right, mid + 1, end, nodeNum * 2 + 1) % 1000000007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    arr.assign(n + 1, 0);
    segTree.assign(1 << (int)ceil(log2(n)) + 1, 0);
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    for(int i = 0;i < m + k;i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            arr[b] = c;
            update(1, n, 1, b, c);
        }
        else cout << subMul(b, c, 1, n, 1) << "\n";
    }
    return 0;
}