#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<vector<int>> map, route;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    map.assign(n, vector<int>(n));
    route.assign(n, vector<int>(n));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            cin >> map[i][j];
            route[i][j] = map[i][j];
        }

    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == k || k == j) continue;
                if(map[i][j] > map[i][k] + map[k][j]){
                    cout << -1 << "\n";
                    return 0;
                }
                if(map[i][j] == map[i][k] + map[k][j]){
                    route[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0;i < n;i++)
        for(int j = i;j < n;j++)
            ans += route[i][j];
    cout << ans << "\n";
    return 0;
}