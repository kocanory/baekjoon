#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, ans1, ans2;
vector<string> arr1, arr2;
vector<vector<bool>> visited;

void dfs(int x, int y, vector<string> &arr){
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || arr[x][y] != arr[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, arr);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr1.assign(n, "");
    arr2.assign(n, "");
    visited.assign(n, vector<bool>(n));
    
    for(int i = 0;i < n;i++){
        cin >> arr1[i];
        arr2[i] = arr1[i];
        for(int j = 0;j < n;j++)
            if(arr2[i][j] == 'G') arr2[i][j] = 'R';
    }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)        {
            if(!visited[i][j]){
                visited[i][j] = true;
                dfs(i, j, arr1);
                ans1++;
            }    
        }
        
    visited.assign(n, vector<bool>(n));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)        {
            if(!visited[i][j]){
                visited[i][j] = true;
                dfs(i, j, arr2);
                ans2++;
            }    
        }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}