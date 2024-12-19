#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> arr;
vector<pair<int, int>> segTree;

pair<int, int> init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = {arr[start] % 2, !(arr[start] % 2)};
    int mid = (start + end) / 2;
    pair<int, int> leftChild = init(start, mid, nodeNum * 2);
    pair<int, int> rightChild = init(mid + 1, end, nodeNum * 2 + 1);
    return segTree[nodeNum] = {leftChild.first + rightChild.first, leftChild.second + rightChild.second};
}
pair<int, int> update(int start, int end, int nodeNum, int target, int val){
    if(target < start || target > end) return segTree[nodeNum];
    if(start == end) return segTree[nodeNum] = {val % 2, !(val % 2)};
    int mid = (start + end) / 2;
    pair<int, int> leftChild = update(start, mid, nodeNum * 2, target, val);
    pair<int, int> rightChild = update(mid + 1, end, nodeNum * 2 + 1, target, val);
    return segTree[nodeNum] = {leftChild.first + rightChild.first, leftChild.second + rightChild.second};
}

pair<int, int> find(int left, int right, int start, int end, int nodeNum){
    if(end < left || start > right) return {0, 0};
    if(left <= start && end <= right) return segTree[nodeNum];
    int mid = (start + end) / 2;
    pair<int, int> leftChild = find(left, right, start, mid, nodeNum * 2);
    pair<int, int> rightChild = find(left, right, mid + 1, end, nodeNum * 2 + 1);
    return {leftChild.first + rightChild.first, leftChild.second + rightChild.second};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, 0);
    segTree.assign(1 << ((int)ceil(log2(n)) + 1), pair<int, int>());

    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);

    cin >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) update(1, n, 1, b, c);
        else if(a == 2) cout << find(b, c, 1, n, 1).second << "\n";
        else cout << find(b, c, 1, n, 1).first << "\n";
    }
}