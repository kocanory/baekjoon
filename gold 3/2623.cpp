#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m;
vector<int> inDeg, answer;
unordered_map<int, vector<int>> graph;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    inDeg.assign(n + 1, 0);
    for(int i = 0;i < m;i++){
        int cnt;
        cin >> cnt;
        vector<int> temp(cnt);
        for(int j = 0;j < cnt;j++)
            cin >> temp[j];
            
        for(int j = 0;j < cnt - 1;j++){
            inDeg[temp[j + 1]]++;
            graph[temp[j]].push_back(temp[j + 1]);
        }
    }
    
    queue<int> q;
    for(int i = 1;i <= n;i++)
        if(inDeg[i] == 0)
            q.push(i);
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        answer.push_back(now);
        for(auto next : graph[now]){
            inDeg[next]--;
            if(inDeg[next] == 0) q.push(next);
        }
    }

    if(answer.size() != n ) cout << 0 << "\n";
    else{
        for(auto a : answer)
            cout << a << "\n";
    }
    return 0;
}