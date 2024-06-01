#include <iostream>
#include <vector>

using namespace std;

int g, p, n, answer = 0;
vector<int> parent;

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void join(int a, int b){
    a = find(a), b = find(b);
    parent[max(a, b)] = min(a, b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g >> p;
    parent.assign(g + 1, 0);
    for(int i = 1;i <= g;i++) parent[i] = i;

    while(p--){
        cin >> n;
        n = find(n);
        if(n == 0) break;
        join(n, n - 1);
        answer++;
    }
    cout << answer << "\n";
    return 0;
}