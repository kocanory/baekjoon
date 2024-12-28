#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<long long> arr, segTree, res;
vector<tuple<int, int, int, int>> query;
queue<tuple<int, int>> mdf;

long long init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return segTree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

long long update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return segTree[nodeNum];
    if(start == end) return segTree[nodeNum] = val;
    int mid = (start + end) / 2;
    return segTree[nodeNum] = update(start, mid, nodeNum * 2, target, val) + update(mid + 1, end, nodeNum * 2 + 1, target, val);
}

long long find(int left, int right, int start, int end, int nodeNum){
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
    
    cin >> n;
    arr.assign(n + 1, 0);
    segTree.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    cin >> m;
    while(m--){
        int a;
        cin >> a;
        if(a == 1){
            int i, j;
            cin >> i >> j;
            mdf.push({i, j});
        }
        else{
            int k, i, j;
            cin >> k >> i >> j;
            query.push_back({k, query.size(), i, j});
        }
    }
    
    sort(query.begin(), query.end());
    res.assign(query.size(), 0);
    int cnt = 1;
    
    for(auto q : query){
        auto[k, idx, i, j] = q;
        while(cnt <= k && !mdf.empty()){
            auto[target, val] = mdf.front(); mdf.pop();
            update(1, n, 1, target, val);
            cnt++;
        }
        res[idx] = find(i, j, 1, n, 1);
    }
    for(auto r : res) cout << r << "\n";
    return 0;
}