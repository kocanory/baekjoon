#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;
pair<int, int> ans{1e9, 1e9};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n + 1, vector<int>(n + 1, 1e9));
    
    for(int i = 0;i < m;i++){
        int s, e;
        cin >> s >> e;
        arr[s][e] = 1;
        arr[e][s] = 1;
    }
    
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    for(int i = 1;i <= n;i++){
        int sum = 0;
        for(int j = 1;j <= n;j++){
            if(i == j) continue;
            sum += arr[i][j];
        }
        ans = min(ans, {sum, i});
    }
    cout << ans.second << "\n";
    return 0;
}