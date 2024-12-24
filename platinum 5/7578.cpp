#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
long long ans;
vector<int> a, b(1000001), tree;

long long sum(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return sum(left, right, start, mid, nodeNum * 2) + sum(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int update(int start, int end, int nodeNum, int target){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] = 1;
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target) + update(mid + 1, end, nodeNum * 2 + 1, target);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    a.assign(n + 1, 0);
    tree.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        int num;
        cin >> num;
        b[num] = i;
    }

    for(int i = 1;i <= n;i++){
        ans += sum(b[a[i]], n, 1, n, 1);
        update(1, n, 1, b[a[i]]);
    }
    cout << ans << "\n";
    return 0;
}