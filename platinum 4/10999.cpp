#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;
vector<long long> arr, segTree, lazy;

long long init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return segTree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

void lazy_update(int start, int end, int nodeNum){
    if(lazy[nodeNum]){
        segTree[nodeNum] += (end - start + 1) * lazy[nodeNum];
        if(start != end){
            lazy[nodeNum * 2] += lazy[nodeNum];
            lazy[nodeNum * 2 + 1] += lazy[nodeNum];
        }
        lazy[nodeNum] = 0;
    }
}

long long update(int left, int right, int start, int end, int nodeNum, long long val){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return segTree[nodeNum];
    if(left <= start && end <= right){
        segTree[nodeNum] += (end - start + 1) * val;
        if(start != end){
            lazy[nodeNum * 2] += val;
            lazy[nodeNum * 2 + 1] += val;
        }
        return segTree[nodeNum];
    }
    int mid = (start + end) / 2;
    return segTree[nodeNum] = update(left, right, start, mid, nodeNum * 2, val) + update(left, right, mid + 1, end, nodeNum * 2 + 1, val);
}

long long find(int left, int right, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) + find(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    arr.assign(n + 1, 0);
    segTree.assign(1 << (int)ceil(log2(n)) + 1, 0);
    lazy.assign(1 << (int)ceil(log2(n)) + 1, 0);
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    for(int i = 0;i < m + k;i++){
        int a;
        cin >> a;
        if(a == 1){
            long long b, c, d;
            cin >> b >> c >> d;
            update(b, c, 1, n, 1, d);
        }
        else {
            long long b, c;
            cin >> b >> c;
            cout << find(b, c, 1, n, 1) << "\n";
        }
    }

    return 0;
}