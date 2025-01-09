#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m, cnt = 0;
vector<ll> st, en, sal, arr, tree, lazy;
vector<vector<int>> adj;

void dfs(int n){
    st[n] = ++cnt;
    arr[cnt] = sal[n];
    for(auto next : adj[n]) dfs(next);
    en[n] = cnt;
}

ll init(int start, int end, int nodeNum){
    if(start == end) return tree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return tree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

void lazy_update(int start, int end, int nodeNum){
    if(lazy[nodeNum]){
        tree[nodeNum] += (end - start + 1) * lazy[nodeNum];
        if(start != end){
            lazy[nodeNum * 2] += lazy[nodeNum];
            lazy[nodeNum * 2 + 1] += lazy[nodeNum];
        }
        lazy[nodeNum] = 0;
    }
}

ll update(int left, int right, int val, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return tree[nodeNum];
    if(left <= start && end <= right){
        lazy[nodeNum] += val;
        lazy_update(start, end, nodeNum);
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[nodeNum] = update(left, right, val, start, mid, nodeNum * 2) + update(left, right, val, mid + 1, end, nodeNum * 2 + 1);
}

ll find(int left, int right, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
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
    
    cin >> n >> m;
    sal.assign(n + 1, 0);
    arr.assign(n + 1, 0);
    st.assign(n + 1, 0);
    en.assign(n + 1, 0);
    tree.assign(1 << (int)ceil(log2(n)) + 1, 0);
    lazy.assign(1 << (int)ceil(log2(n)) + 1, 0);
    adj.assign(n + 1, vector<int>());

    for(int i = 1;i <= n;i++){
        cin >> sal[i];
        if(i > 1){
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
    }
    dfs(1);
    init(1, n, 1);

    while(m--){
        char c; int a;
        cin >> c >> a;
        if(c == 'p'){
            int x;
            cin >> x;
            update(st[a] + 1, en[a], x, 1, n, 1);
        }
        else cout << find(st[a], st[a], 1, n, 1) << "\n";
    }
    return 0;
}