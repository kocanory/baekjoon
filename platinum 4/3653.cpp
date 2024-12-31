#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int t, n, m;
vector<int> arr, loc;
vector<long long> tree;

int init(int start, int end, int nodeNum){
    if(start == end) return tree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return tree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

int update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] += val;
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target, val) + update(mid + 1, end, nodeNum * 2 + 1, target, val);
}

long long find(int left, int right, int start, int end, int nodeNum){
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
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        arr.assign(n + m + 1, 0);
        loc.assign(n + 1, 0);
        tree.assign(1 << ((int)ceil(log2(n + m)) + 1), 0);
        
        for(int i = 1;i <= n;i++){
            arr[i] = 1;
            loc[i] = n - i + 1;
        }
        init(1, n + m, 1);
        for(int i = 1;i <= m;i++){
            int val;
            cin >> val;
            int cur = loc[val], next = i + n;
            cout << find(cur + 1, next - 1, 1, n + m, 1) << " ";
            arr[cur] = 0;
            arr[next] = 1;
            loc[val] = next;
            update(1, n + m, 1, cur, -1);
            update(1, n + m, 1, next, 1);
        }
        cout << "\n";
    }
    return 0;
}