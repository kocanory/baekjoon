#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, ans = 0;
vector<int> arr, segTree;

int init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return segTree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

int find(int left, int right, int start, int end, int nodeNum){
    if(end < left  || start > right) return 0;
    if(left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) + find(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int check(int amount){
    int s = 1, cnt = 1;
    for(int i = 2;i <= n;i++){
        if(find(s, i, 1, n, 1) > amount){
            s = i;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n + 1, 0);
    segTree.assign(1 << (int)ceil(log2(n)) + 1, 0);
    
    int l = 0, r = 0;
    
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        l = max(l, arr[i]);
    }
    init(1, n, 1);
    
    r = segTree[1];
    
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid) <= m){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}