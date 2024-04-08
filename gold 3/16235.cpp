#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, k, result = 0;
vector<vector<vector<int>>> arr;
vector<vector<int>> food, A;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    
    arr.assign(n + 1, vector<vector<int>>(n + 1));
    food.assign(n + 1, vector<int>(n + 1, 5));
    A.assign(n + 1, vector<int>(n + 1));
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> A[i][j];
         
    for(int i = 0;i < m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[x][y].push_back(z);
    }
    
    while(k--){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(arr[i][j].empty()) continue;
                sort(arr[i][j].begin(), arr[i][j].end());
                vector<int> in;
                int sum = 0;
                for(auto t : arr[i][j]){
                    if(food[i][j] >= t){
                        food[i][j] -= t;
                        in.push_back(t + 1);
                    }
                    else sum += (t / 2);
                }
                arr[i][j] = in;
                food[i][j] += sum;
            }
        }
        
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(auto t : arr[i][j]){
                    if(t % 5 == 0){
                        for(int k = 0;k < 8;k++){
                            int nx = i + dx[k], ny = j + dy[k];
                            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                            arr[nx][ny].push_back(1);
                        }
                    }
                }
                food[i][j] += A[i][j];
            }
        }
    }
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            result += arr[i][j].size();

    cout << result << "\n";
    return 0;
}