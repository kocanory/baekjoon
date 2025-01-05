#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m, mod = 1e9 + 7;
vector<ll> arr, tree;
vector<pair<ll, ll>> lazy;

ll init(int start, int end, int nodeNum){
    if(start == end) return tree[nodeNum] = arr[start];
    int mid = (start + end) / 2;
    return tree[nodeNum] = (init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1)) % mod;
}

void lazy_update(int start, int end, int nodeNum){
    auto [a, b] = lazy[nodeNum];
    if(a != 1 || b){
        tree[nodeNum] = (tree[nodeNum] * a + (end - start + 1) * b) % mod;
        if(start != end){
            lazy[nodeNum * 2].second = (lazy[nodeNum * 2].second * a + b) % mod;
            lazy[nodeNum * 2].first = lazy[nodeNum * 2].first * a % mod;
            lazy[nodeNum * 2 + 1].second = (lazy[nodeNum * 2 + 1].second * a + b) % mod;
            lazy[nodeNum * 2 + 1].first = lazy[nodeNum * 2 + 1].first * a % mod;
        }
        lazy[nodeNum] = {1, 0};
    }
}

ll update_add(int left, int right, int val, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return tree[nodeNum];
    if(left <= start && end <= right){
        lazy[nodeNum].second = (lazy[nodeNum].second + val) % mod;
        lazy_update(start, end, nodeNum);
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[nodeNum] = (update_add(left, right, val, start, mid, nodeNum * 2) + update_add(left, right, val, mid + 1, end, nodeNum * 2 + 1)) % mod;
}

ll update_mul(int left, int right, int val, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return tree[nodeNum];
    if(left <= start && end <= right){
        lazy[nodeNum].first = (lazy[nodeNum].first * val) % mod;
        lazy_update(start, end, nodeNum);
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return tree[nodeNum] = (update_mul(left, right, val, start, mid, nodeNum * 2) + update_mul(left, right, val, mid + 1, end, nodeNum * 2 + 1)) % mod;
}

ll find(int left, int right, int start, int end, int nodeNum){
    lazy_update(start, end, nodeNum);
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree[nodeNum];
    int mid = (start + end) / 2;
    return (find(left, right, start, mid, nodeNum * 2) + find(left, right, mid + 1, end, nodeNum * 2 + 1)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n + 1, 0);
    tree.assign(1 << ((int)ceil(log2(n)) + 1), 0);
    lazy.assign(1 << ((int)ceil(log2(n)) + 1), {1, 0});
    
    for(int i = 1;i <= n;i++) cin >> arr[i];
    init(1, n, 1);
    
    cin >>m;
    while(m--){
        int a, x, y, v;
        cin >> a >> x >> y;
        if(a == 4) cout << find(x, y, 1, n, 1) << "\n";
        else{
            cin >> v;
            if(a == 1) update_add(x, y, v, 1, n, 1);
            else if(a == 2) update_mul(x, y, v, 1, n, 1);
            else{
                update_mul(x, y, 0, 1, n, 1);
                update_add(x, y, v, 1, n, 1);
            }
        }
    }
    return 0;
}