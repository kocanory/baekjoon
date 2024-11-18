#include <iostream>
#include <vector>

using namespace std;

int n, k, s;
vector<vector<int>> map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    map.assign(n + 1, vector<int>(n + 1));
    
    for(int i = 0;i < k;i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = -1;
        map[b][a] = 1;
    }

    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){
                if(map[i][k] == 1 && map[k][j] == 1) map[i][j] = 1;
                if(map[i][k] == -1 && map[k][j] == -1) map[i][j] = -1;
            }
            
    cin >> s;
    for(int i = 0;i < s;i++){
        int a, b;
        cin >> a >> b;
        cout << map[a][b] << "\n";
    }
    return 0;
}