#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<vector<int>> arr, tree;

int init_y(int xnode, int x, int start, int end, int nodeNum){
    if(start == end) return tree[xnode][nodeNum] = arr[x][start];

    int mid = (start + end) / 2;
    return tree[xnode][nodeNum] = init_y(xnode, x, start, mid, nodeNum * 2) + init_y(xnode, x, mid + 1, end, nodeNum * 2 + 1);
}

void init_x(int start, int end, int nodeNum){
    if(start == end){
        init_y(nodeNum, start, 1, n, 1);
        return;
    }
    int mid = (start + end) / 2;
    init_x(start, mid, nodeNum * 2);
    init_x(mid + 1, end, nodeNum * 2 + 1);
    for(int i = 1;i < tree[nodeNum].size();i++)
        tree[nodeNum][i] = tree[nodeNum * 2][i] + tree[nodeNum * 2 + 1][i];
}

int find_y(int xnode, int y1, int y2, int start, int end, int nodeNum){
    if(end < y1 || start > y2) return 0;
    if(y1 <= start && end <= y2) return tree[xnode][nodeNum];
    int mid = (start + end) / 2;
    return find_y(xnode, y1, y2, start, mid, nodeNum * 2) + find_y(xnode, y1, y2, mid + 1, end, nodeNum * 2 + 1);
}
int find_x(int x1, int y1, int x2, int y2, int start, int end, int nodeNum){
    if(end < x1 || start > x2) return 0;
    if(x1 <= start && end <= x2) return find_y(nodeNum, y1, y2, 1, n, 1);
    int mid = (start + end) / 2;
    return find_x(x1, y1, x2, y2, start, mid, nodeNum * 2) + find_x(x1, y1, x2, y2, mid + 1, end, nodeNum * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n + 1, vector<int>(n + 1));
    int size = 1 << ((int)ceil(log2(n)) + 1);
    tree.assign(size, vector<int>(size));
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> arr[i][j];
    
    init_x(1, n, 1);
    
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << find_x(x1, y1, x2, y2, 1, n, 1) << "\n";
    }
    
    return 0;
}