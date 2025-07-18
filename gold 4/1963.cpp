#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

int t;
string a, b;
vector<bool> check(10000, true);

string bfs(string a, string b){
    queue<pair<string, int>> q;
    unordered_map<string, bool> visited;
    
    q.push({a, 0});
    visited[a] = true;
    
    while(!q.empty()){
        auto[now, cnt] = q.front(); q.pop();
        if(now == b) return to_string(cnt);
        
        for(int i = 0;i < 4;i++)
            for(int j = 0;j < 10;j++){
                if(i == 0 && j == 0) continue;
                string nxt = now;
                nxt[i] = char(j + '0');
                if(!visited[nxt] && check[stoi(nxt)]){
                    q.push({nxt, cnt + 1});
                    visited[nxt] = true;
                }
            }
    }
    return "Impossible";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 2;i <= sqrt(10000);i++){
        if(check[i] == false) continue;
        for(int j = i * i;j < 10000;j += i)
            check[j] = false;
    }
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }

    return 0;
}