#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, -1, 0, 1};
int dy[] = {0, 1, 0, -1, 0};

int n;
vector<string> arr(3);
vector<bool> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    while(n--){
        int val = 0, level = 0;
        for(int i = 0;i < 3;i++) {
            cin >> arr[i];
            for(int j = 0;j < 3;j++)
                if(arr[i][j] == '*')
                    val |= 1 << i * 3 + j;
        }
        
        queue<int> q;
        q.push(val);
        
        visited.assign(1 << 9, false);
        visited[val] = true;
        
        bool solve = false;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int now = q.front(); q.pop();
                if(!now){
                    solve = true;
                    break;
                }
                
                for(int i = 0;i < 9;i++){
                    int temp = now;
                    int x = i / 3, y = i % 3;
                    for(int j = 0;j < 5;j++){
                        int nx = x + dx[j], ny = y + dy[j];
                        if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
                        temp ^= 1 << nx * 3 + ny;
                    }
                    if(!visited[temp]){
                        visited[temp] = true;
                        q.push(temp);
                    }
                }
            }
            if(solve){
                break;
            }
            level++;
        }
        cout << level << "\n";
    }

    return 0;
}