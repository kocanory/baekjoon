#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int s;
vector<vector<bool>> check(2001, vector<bool>(2001, false));
queue<tuple<int, int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    q.push({1, 0, 0});
    check[1][0] = true;
    
    while(!q.empty()){
        auto[now, clip, cnt] = q.front(); q.pop();
        if(now == s){
            cout << cnt;
            break;
        }
        
        if(clip != 0 && now + clip <= 2000 && !check[now + clip][clip]){
            check[now + clip][clip] = true;
            q.push({now +clip, clip, cnt + 1});
        }
        
        if(!check[now][now]){
            check[now][now] = true;
            q.push({now, now, cnt + 1});
        }
        
        if(now - 1 >= 0 && !check[now - 1][clip]){
            check[now - 1][clip] = true;
            q.push({now - 1, clip, cnt + 1});
        }
    }

    return 0;
}