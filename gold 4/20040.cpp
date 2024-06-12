#include <iostream>
#include <vector>


using namespace std;

int n, m, answer = 0;
vector<int> parent;

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void join(int a, int b){
    a = find(a), b = find(b);
    parent[max(a, b)] = min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    parent.assign(n, 0);
    for(int i = 0;i < n;i++) parent[i] = i;

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)){
            answer = i + 1;
            break;
        }
        join(a, b);
    }
    cout << answer << "\n";
    return 0;
}