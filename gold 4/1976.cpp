#include <iostream>
#include <vector>

using namespace std;

int n, m;
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

    cin >> n >> m;
    parent.assign(n + 1, 0);
    for(int i = 1;i <= n;i++) parent[i] = i;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int city;
            cin >> city;
            if(city) join(i, j);
        }
    }

    int back = 0, now;
    for(int i = 0;i < m;i++){
        cin >> now;
        if(back == 0) back = find(now);
        else{
            if(find(now) == back) continue;
            else {
                cout << "NO" <<"\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    return 0;
}