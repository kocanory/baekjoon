#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, k;
vector<int> arr, segTree;

int init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = (arr[start] > 0 ? 1 : (arr[start] < 0 ? -1 : 0));
    int mid = (start + end) / 2;
    return segTree[nodeNum] = init(start, mid, nodeNum * 2) * init(mid + 1, end, nodeNum * 2 + 1);
}

int update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return segTree[nodeNum];
    if(start == end) return segTree[nodeNum] = (val > 0 ? 1 : (val < 0 ? -1 : 0));
    int mid = (start + end) / 2;
    return segTree[nodeNum] = update(start, mid, nodeNum * 2, target, val) * update(mid + 1, end, nodeNum * 2 + 1, target, val);
}

int find(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return 1;
    if(left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) * find(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n >> k){
        arr.assign(n + 1, 0);
        segTree.assign(1 << ((int)ceil(log2(n)) + 1), 0);

        for(int i = 1;i <= n;i++) cin >> arr[i];
        init(1, n, 1);
        while(k--){
            char cmd; int a, b;
            cin >> cmd >> a >> b;
            if(cmd == 'C') update(1, n, 1, a, b);
            else {
                int val = find(a, b, 1, n, 1);
                cout << (val > 0 ? '+' : (val < 0 ? '-' : '0'));
            }
        }
        cout << "\n";
    }
}