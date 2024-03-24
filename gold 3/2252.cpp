#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> graph;
vector<int> inDeg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    inDeg.resize(n + 1, 0);
    
    while(m--){
        int t, s;
        cin >> t >> s;
        graph[t].push_back(s);
        inDeg[s]++;
    }
    
    queue<int> q;
    
    for(int i = 1;i <= n;i++)
        if(inDeg[i] == 0) q.push(i);
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        cout << now << " ";
        for(auto next : graph[now]){
            inDeg[next]--;
            if(inDeg[next] == 0) q.push(next);
        }
    }
    
    return 0;
}