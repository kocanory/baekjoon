#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>

#define ll long long
#define tii tuple<ll, ll>

using namespace std;

int n, group, maxCount = 0;
vector<tuple<tii, tii>> arr;
vector<int> parent;
unordered_map<int, int> check;

ll ccw(tii p1, tii p2, tii p3){
    auto[x1, y1] = p1;
    auto[x2, y2] = p2;
    auto[x3, y3] = p3;

    ll s = x1 * y2 + x2 * y3 + x3 * y1;
    s -= x2 * y1 + x3 * y2 + x1 * y3;

    if(s > 0) return 1;
    else if(s == 0) return 0;
    else return -1;
}

bool isIntersect(tuple<tii, tii> l1, tuple<tii, tii> l2){
    auto [p1, p2] = l1;
    auto [p3, p4] = l2;

    ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if(p1p2 == 0 && p3p4 == 0){
        if(p1 > p2) swap(p1, p2);
        if(p3 > p4) swap(p3, p4);
        return p3 <= p2 && p1 <= p4;
    }
    return p1p2 <= 0 && p3p4 <= 0;
}

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.assign(n + 1, tuple<tii, tii>());
    parent.assign(n + 1, 0);

    for(int i = 1;i <= n;i++) parent[i] = i;

    for(int i = 1;i <= n;i++){
        ll x1, y1, x2 ,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[i] = {{x1, y1}, {x2, y2}};
    }

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(isIntersect(arr[i], arr[j]))
            {
                int a = find(i), b = find(j);
                parent[max(a, b)] = min(a, b);
            }
        }
    }

    for(int i = 1;i <= n;i++) parent[i] = find(parent[i]);
    for(int i = 1;i <= n;i++) {
        check[parent[i]]++;
    }

    for(auto c : check) maxCount = max(maxCount, c.second);
    cout << check.size() << "\n";
    cout << maxCount << "\n";
    return 0;
}