#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int n, result = 1e9;
vector<int> people;
vector<vector<bool>> node;
vector<bool> visited, Select;

bool checkConnect(vector<int> v, bool t){
    visited.assign(n + 1, false);
    queue<int> q;
    q.push(v[0]);
    visited[v[0]] = true;
    int count = 1;
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int i = 1;i <= n;i++){
            if(node[now][i] && Select[i] == t && !visited[i]){
                visited[i] = true;
                count++;
                q.push(i);
            }
        }
    }
    if(v.size() == count) return true;
    return false;
    
}

bool check(){
    vector<int> a, b;
    
    for(int i = 1;i <= n;i++){
        if(Select[i]) a.push_back(i);
        else b.push_back(i);
    }
    
    if(a.empty() || b.empty()) return false;
    
    if(!checkConnect(a, true)) return false;
    if(!checkConnect(b, false)) return false;
    return true;
    
}

void calc(){
    int aNum = 0, bNum = 0;
    
    for(int i = 1;i <= n;i++){
        if(Select[i]) aNum += people[i];
        else bNum += people[i];
    }
    
    result = min(result, abs(aNum - bNum));
}

void dfs(int idx, int count){
    if(count >= 1)
        if(check())
            calc();
            
    for(int i = idx ;i <= n;i++){
        if(Select[i]) continue;
        Select[i] = true;
        dfs(i, count + 1);
        Select[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> n;
    people.assign(n + 1, 0);
    Select.assign(n + 1, false);
    node.assign(n + 1, vector<bool>(n + 1, false));
    
    for(int i = 1;i <= n;i++)
        cin >> people[i];
    
        
    for(int i = 1;i <= n;i++){
        int count;
        cin >> count;
        while(count--){
            int num;
            cin >> num;
            node[i][num] = true;
            node[num][i] = true;
        }
    }
    
    dfs(1, 0);
    if(result == 1e9) cout << -1 << "\n";
    else cout << result << "\n";
    return 0;
}