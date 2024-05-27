#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, answer = 0;
vector<tuple<int, int, int>> info;
vector<tuple<int, int>> x, y, z;
vector<int> parent;

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void join(int a, int b){
    a = find(a), b = find(b);
    parent[max(a, b)] = min(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    parent.assign(n, 0);
    for(int i = 0;i < n;i++) parent[i] = i;
    for(int i = 0;i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i = 0;i < n - 1;i++){
        info.push_back({get<0>(x[i + 1]) - get<0>(x[i]), get<1>(x[i + 1]), get<1>(x[i])});
        info.push_back({get<0>(y[i + 1]) - get<0>(y[i]), get<1>(y[i + 1]), get<1>(y[i])});
        info.push_back({get<0>(z[i + 1]) - get<0>(z[i]), get<1>(z[i + 1]), get<1>(z[i])});
    }

    sort(info.begin(), info.end());

    for(auto i : info){
        auto[cost, dest, start] = i;
        if(find(dest) != find(start)){
            join(dest, start);
            answer += cost;
        }
    }
    cout << answer << "\n";
    return 0;
}