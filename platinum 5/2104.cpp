#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<long long> arr, sum, minIdx;

long long cmp(long long a, long long b){
    if(a == -1) return b;
    if(b == -1) return a;
    if(arr[a] < arr[b]) return a;
    return b;
}

long long init_sum(int start, int end, int nodeNum){
    if(start == end) return sum[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return sum[nodeNum] = init_sum(start, mid, nodeNum * 2) + init_sum(mid + 1, end, nodeNum * 2 + 1);
}

long long find_sum(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return sum[nodeNum];
    int mid = (start + end) / 2;
    return find_sum(left, right, start, mid, nodeNum * 2) + find_sum(left, right, mid + 1, end, nodeNum * 2 + 1);
}

long long init_idx(int start, int end, int nodeNum){
    if(start == end) return minIdx[nodeNum] = start;
    int mid = (start + end) / 2;
    return minIdx[nodeNum] = cmp(init_idx(start, mid, nodeNum * 2), init_idx(mid + 1, end, nodeNum * 2 + 1)); 
}

long long find_idx(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return -1;
    if(left <= start && end <= right) return minIdx[nodeNum];
    int mid = (start + end) / 2;
    return cmp(find_idx(left, right, start, mid, nodeNum * 2), find_idx(left, right, mid + 1, end, nodeNum * 2 + 1));
}

long long find(int start, int end){
    if(start == end) return arr[start] * arr[start];
    int idx = find_idx(start, end, 1, n, 1);
    long long res = find_sum(start, end, 1, n, 1) * arr[idx];
    if(start != idx) res = max(res, find(start, idx - 1));
    if(idx != end) res = max(res, find(idx + 1, end));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n + 1, 0);
    sum.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    minIdx.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init_sum(1, n, 1);
    init_idx(1, n, 1);
    cout << find(1, n) << "\n";
    return 0;
}