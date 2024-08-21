#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, sum;
vector<tuple<int, int, int>> arr;
vector<int> parent;

int find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    parent[min(a, b)] = max(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    parent.assign(n + 1, 0);
    for(int i = 1;i <= n;i++) parent[i] = i;
    for(int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({c, a, b});
    }
    sort(arr.begin(), arr.end());

    for(auto &a : arr) {
        auto[cost, s, e] = a;
        if(find(s) != find(e)) {
            join(s, e);
            sum += cost;
        }
    }
    cout << sum << endl;
    return 0;
}