#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> arr;
vector<pair<int, int>> segTree;

pair<int, int> init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = {arr[start], arr[start]};
    int mid = (start + end) / 2;
    pair<int, int> left_child = init(start, mid, nodeNum * 2);
    pair<int, int> right_child = init(mid + 1, end, nodeNum * 2 + 1);
    return segTree[nodeNum] = {min(left_child.first, right_child.first), max(left_child.second, right_child.second)};
}

pair<int, int> find(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return {1e9, 1};
    if(left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    pair<int, int> left_child = find(left, right, start, mid, nodeNum * 2);
    pair<int, int> right_child = find(left, right, mid + 1, end, nodeNum * 2 + 1);
    return {min(left_child.first, right_child.first), max(left_child.second, right_child.second)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n + 1, 0);
    segTree.assign(1 << (int)ceil(log2(n)) + 1, pair<int, int>());
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        auto[Min, Max] = find(a, b, 1, n, 1);
        cout << Min << " " << Max << '\n';
    }
    return 0;
}