include <iostream>
#include <vector>

using namespace std;

int ans = 30;
int arr[10][10];
int paper[5] = {5, 5, 5, 5, 5};

bool check(int x, int y, int size){
    for(int i = x;i <= x + size;i++)
        for(int j = y;j <= y + size;j++)
            if(!arr[i][j]) return false;
    return true;
}

void fill(int x, int y, int size, int val){
    for(int i = x;i <= x + size;i++)
        for(int j = y;j <= y + size;j++)
            arr[i][j] = val;    
}

bool all_check(){
    for(int i = 0;i < 10;i++)
        for(int j = 0;j < 10;j++)
            if(arr[i][j]) return false;
    return true;
}

void dfs(int cnt){
    if(ans < cnt) return;
    if(all_check()){
        ans = min(ans, cnt);
        return;
    }
    
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            if(arr[i][j]){
                for(int k = 4;k >= 0;k--){
                    if(i + k >= 10 || j + k >= 10) continue;
                    if(paper[k] && check(i, j, k)){
                        paper[k]--;
                        fill(i, j, k, 0);
                        dfs(cnt + 1);
                        fill(i, j, k, 1);
                        paper[k]++;
                    }
                }
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0;i < 10;i++)
        for(int j = 0;j < 10;j++)
            cin >> arr[i][j];
    dfs(0);
    cout << (ans == 30 ? -1 : ans) << "\n";
    return 0;
}