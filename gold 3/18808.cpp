#include <iostream>
#include <vector>

using namespace std;

int n, m, k, r, c, ans = 0;
vector<vector<int>> arr, sticker, tmp;

bool isPossible(int x, int y){
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            if(sticker[i][j] && arr[x + i][y + j])
                return false;
    return true;
}

void paste(int x, int y){
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            if(sticker[i][j])
                arr[x + i][y + j] = 1;
}

void rotate(){
    tmp.assign(c, vector(r, 0));
    
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            tmp[j][r - 1 - i] = sticker[i][j];
            
    swap(r, c);
    sticker = tmp;
}

void solve(){
    for(int rot = 0;rot < 4;rot++){
        for(int i = 0;i < n - r + 1;i++)
            for(int j = 0;j < m - c + 1;j++)
                if(isPossible(i, j)){
                    paste(i, j);
                    return;
                }
        rotate();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    arr.assign(n, vector(m, 0));
    
    while(k--){
        cin >> r >> c;
        sticker.assign(r, vector(c, 0));
        
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                cin >> sticker[i][j];
                
        solve();
    }
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            ans += arr[i][j];
    cout << ans;
    return 0;
}