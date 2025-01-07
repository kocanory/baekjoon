#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int t, n;
vector<pair<int, int>> arr;
vector<int> tree, y_vec;

int update(int start, int end, int nodeNum, int target){
    if(target < start || target > end) return tree[nodeNum];
    if(start == end) return tree[nodeNum] += 1;
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(start, mid, nodeNum * 2, target) + update(mid + 1, end, nodeNum * 2 + 1, target);
}

int find(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return find(left, right, start, mid, nodeNum * 2) + find(left, right, mid + 1, end, nodeNum * 2 + 1); 
}

bool cmp_xy(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

bool cmp_y(int a, int b){
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(n, {0, 0});
        tree.assign(1 << (int)ceil(log2(n)) + 1, 0);
        y_vec.assign(n, 0);
        
        for(int i = 0;i < n;i++){
            cin >> arr[i].first >> arr[i].second;
            y_vec[i] = arr[i].second;
        }
        
        sort(arr.begin(), arr.end(), cmp_xy);
        sort(y_vec.begin(), y_vec.end(), cmp_y);
        
        long long ans = 0;
        for(auto [x, y] : arr){
            int idx = distance(y_vec.begin(), upper_bound(y_vec.begin(), y_vec.end(), y, cmp_y)) - 1;
            ans += find(0, idx, 0, n - 1, 1);
            update(0, n - 1, 1, idx);
        }
        cout << ans << "\n";
    }
    return 0;
}