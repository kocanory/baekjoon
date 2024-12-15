#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<long long> segTree;

void update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return;
    segTree[nodeNum] += val;
    if(start != end){
        int mid = (start + end) / 2;
        update(start, mid, nodeNum * 2, target, val);
        update(mid + 1, end, nodeNum * 2 + 1, target, val);
    }
}

int find(int start, int end, int nodeNum, int target){
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(segTree[nodeNum * 2] >= target) return find(start, mid, nodeNum * 2, target);
    return find(mid + 1, end, nodeNum * 2 + 1, target - segTree[nodeNum * 2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    segTree.assign(1 << (int)ceil(log2(1e6)) + 1, 0);
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        if(a == 1){
            int b;
            cin >> b;
            int idx = find(1, 1e6, 1, b);
            cout << idx << "\n";
            update(1, 1e6, 1, idx, -1);
        }
        else{
            int b, c;
            cin >> b >> c;
            update(1, 1e6, 1, b, c);
        }
    }

    return 0;
}