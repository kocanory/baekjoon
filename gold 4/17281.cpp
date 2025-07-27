#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<vector<int>> arr;
vector<int> check(9), order(9);

void play(){
    int score = 0, idx = 0;
    for(int i = 0;i < n;i++){
        int out = 0;
        vector<int> base(4);
        
        while(out < 3){
            int player = arr[i][order[idx]];
            if(player == 0) out++;
            else if(player == 1){
                score += base[3];
                base = {0, 1, base[1], base[2]};
            }
            else if(player == 2){
                score += base[2] + base[3];
                base = {0, 0, 1, base[1]};
            }
            else if(player == 3){
                score += base[1] + base[2] + base[3];
                base = {0, 0, 0, 1};
            }
            else{
                score += base[1] + base[2] + base[3] + 1;
                base = {0, 0, 0, 0};
            }
            idx = (idx + 1) % 9;
        }
    }
    ans = max(ans, score);
}

void dfs(int cnt){
    if(cnt == 9){
        play();
        return;
    }
    for(int i = 0;i < 9;i++){
        if(check[i]) continue;
        check[i] = 1;
        order[i] = cnt;
        dfs(cnt + 1);
        check[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, vector<int>(9));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < 9;j++) cin >> arr[i][j];

    check[3] = 1;
    order[3] = 0;
    dfs(1);
    
    cout << ans;
    return 0;
}