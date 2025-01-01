#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, Max = 500001;
vector<int> arr, tree;

void compress(){
    vector<int> temp(arr);
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(auto &a : arr) a = distance(temp.begin(), lower_bound(temp.begin(), temp.end(), a)) + 1;
}

int update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] += val;
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target, val) + update(mid + 1, end, nodeNum * 2 + 1, target, val);
}

int find(int left, int right, int start, int end, int nodeNum){
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
    
    cin >> n;
    arr.assign(n, 0);
    tree.assign(1 << ((int)ceil(log2(Max)) + 1), 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    compress();
    
    for(int i = 0;i < n;i++){
        cout << i + 1 - find(1, arr[i] - 1, 1, Max, 1) << "\n";
        update(1, Max, 1, arr[i], 1);
    }
    return 0;
}