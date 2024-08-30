#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, t, c, n1, n2;
vector<int> parent;
unordered_map<int, vector<int>> connected;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void join(int a, int b){
    a = find(a), b = find(b);
    parent[max(a, b)] = min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    parent.assign(n + 1, 0);
    for(int i = 1;i <= n;i++) parent[i] = i;

    cin >> t;
    for(int i = 0;i < t;i++){
        int num;
        cin >> num;
        parent[num] = 0;
    }
    
    for(int i = 0;i < m;i++){
        cin >> c >> n1;
        connected[i].push_back(n1);
        for(int j = 1;j < c;j++){
            cin >> n2;
            join(n1, n2);
        }
    }
    
    int ans = m;
    for(int i = 0;i < m;i++){
        if(!find(connected[i].front())){
            ans--;
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}