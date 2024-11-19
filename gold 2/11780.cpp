#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> map, route;
vector<int> v;

void tracking(int s, int e){
    if(route[s][e] == 0){
        v.push_back(s);
        v.push_back(e);
        return;
    }
    tracking(s, route[s][e]);
    v.pop_back();
    tracking(route[s][e], e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    map.assign(n + 1, vector<int>(n + 1, 1e9));
    route.assign(n + 1, vector<int>(n+ 1, 0));
    
    for(int i = 0;i <m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = min(map[a][b], c);
    }
    
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j) continue;
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                    route[i][j] = k;
                }
            }
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << (map[i][j] == 1e9 ? 0 : map[i][j]) << " ";
        }
        cout << "\n";
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(map[i][j] == 1e9) cout << 0;
            else{
                v.clear();
                tracking(i, j);
                cout << v.size() << " ";
                for(auto &a : v) cout << a << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}