#include <iostream>
#include <vector>
#include <climits>

using namespace std;
vector<vector<bool>> visited;

int n, m, h, result = INT_MAX;

bool checkLadder(){
    for(int i = 1;i <= n;i++){
        int now = i;
        for(int j = 1;j <= h;j++){
            if(visited[now][j]) now++;
            else if(visited[now - 1][j]) now--;
        }
        if(now != i) return false;
    }
    return true;
}

void select(int line, int count){
    if(count > 3) return;
    if(checkLadder()){
        result = min(result, count);
        return;
    }
    
    for(int i = line;i <= h;i++){
        for(int j = 1;j < n;j++){
            if(visited[j][i]) continue;
            if(visited[j + 1][i]) continue;
            if(visited[j - 1][i]) continue;
            
            visited[j][i] = true;
            select(i, count + 1);
            visited[j][i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;
    visited.assign(n + 1, vector<bool>(h + 1, false));
    
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        visited[b][a] = true;
    }
    
    select(1, 0);
    
    if(result == INT_MAX) result = -1;
    cout << result << "\n";
    return 0;
}