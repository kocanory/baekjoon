#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<vector<long long>> arr, segTree;

void init_y(int start, int end, int nodeNum, int xnode, int idx){
    if(start == end){
        segTree[xnode][nodeNum] = arr[idx][start];
        return;
    }
    
    int mid = (start + end) / 2;
    init_y(start, mid, nodeNum * 2, xnode, idx);
    init_y(mid + 1, end, nodeNum * 2 + 1, xnode, idx);
    segTree[xnode][nodeNum] = segTree[xnode][nodeNum * 2] + segTree[xnode][nodeNum * 2 + 1];
}

void init_x(int start, int end, int nodeNum){
    if(start == end){
        init_y(1, n, 1, nodeNum, start);
        return;
    }
    int mid = (start + end) / 2;
    init_x(start, mid, nodeNum * 2);
    init_x(mid + 1, end, nodeNum * 2 + 1);
    for(int i = 1;i < segTree[nodeNum].size();i++)
        segTree[nodeNum][i] = segTree[nodeNum * 2][i] + segTree[nodeNum * 2 + 1][i];
}

void update_y(int start, int end, int nodeNum, int xnode, int y, int val){
    if(y < start || y > end) return;
    if(start == end){
        segTree[xnode][nodeNum] = val;
        for(int i = xnode >> 1;i >= 1;i >>= 1) segTree[i][nodeNum] = segTree[i * 2][nodeNum] + segTree[i * 2 + 1][nodeNum];
        return;
    }
    int mid = (start + end) / 2;
    update_y(start, mid, nodeNum * 2, xnode, y, val);
    update_y(mid + 1, end, nodeNum * 2 + 1, xnode, y, val);
    segTree[xnode][nodeNum] = segTree[xnode][nodeNum * 2] + segTree[xnode][nodeNum * 2 + 1];
    for(int i = xnode >> 1;i >= 1;i >>= 1) segTree[i][nodeNum] = segTree[i * 2][nodeNum] + segTree[i * 2 + 1][nodeNum];
}

void update_x(int start, int end, int nodeNum, int x, int y, int val){
    if(x < start || x > end) return;
    if(start == end){
        update_y(1, n, 1, nodeNum, y, val);
        return;
    }
    int mid = (start + end) / 2;
    update_x(start, mid, nodeNum * 2, x, y, val);
    update_x(mid + 1, end, nodeNum * 2 + 1, x, y, val);
}

long long find_y(int start, int end, int nodeNum, int xnode, int y1, int y2){
    if(y2 < start || y1 > end) return 0;
    if(y1 <= start && end <= y2) return segTree[xnode][nodeNum];
    int mid = (start + end) / 2;
    return find_y(start, mid, nodeNum * 2, xnode, y1, y2) + find_y(mid + 1, end, nodeNum * 2 + 1, xnode, y1, y2);
}

long long find_x(int start, int end, int nodeNum, int x1, int y1, int x2, int y2){
    if(x2 < start || x1 > end) return 0;
    if(x1 <= start && end <= x2) return find_y(1, n, 1, nodeNum, y1, y2);
    int mid = (start + end) / 2;
    return find_x(start, mid, nodeNum * 2, x1, y1, x2, y2) + find_x(mid + 1, end, nodeNum * 2 + 1, x1, y1, x2, y2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    int size = 1 << ((int)ceil(log2(n)) + 1);
    arr.assign(n + 1, vector<long long>(n + 1));
    segTree.assign(size, vector<long long>(size));
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> arr[i][j];
    
    init_x(1, n, 1);
    
    while(m--){
        int w;
        cin >> w;
        if(w){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << find_x(1, n, 1, x1, y1, x2, y2) << "\n";
        }
        else{
            int x, y, c;
            cin >> x >> y >> c;
            update_x(1, n, 1, x, y, c);
        }
    }
    return 0;
}