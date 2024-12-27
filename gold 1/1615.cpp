#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
long long ans;
vector<pair<int, int>> arr;
vector<int> tree;

long long find(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) + find(left, right, mid + 1, end, nodeNum * 2 + 1);
}

int update(int start, int end, int nodeNum, int target){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return ++tree[nodeNum];
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target) + update(mid + 1, end, nodeNum * 2 + 1, target);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(m, pair<int, int>());
    tree.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    
    for(auto &a : arr)
        cin >> a.first >> a.second;
    
    sort(arr.begin(), arr.end());
    for(auto [i, j] : arr){
        ans += find(j + 1, n, 1, n, 1);
        update(1, n, 1, j);
    }
    cout << ans << "\n";
    return 0;
}