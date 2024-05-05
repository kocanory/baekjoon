#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, m;
vector<int> inDeg;
map<int, vector<int>> tree;

void bfs(){
    priority_queue<int> pq;
    for(int i = 1;i <= n;i++)
        if(inDeg[i] == 0) pq.push(-i);
        
    while(!pq.empty()){
        int now = pq.top(); pq.pop();
        now = -now;
        
        cout << now << " ";
        
        for(auto next : tree[now]){
            inDeg[next]--;
            if(inDeg[next] == 0)
                pq.push(-next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    inDeg.assign(n + 1, 0);
    
    for(int i = 0;i < m;i++){
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
        inDeg[c]++;
    }
    bfs();
    return 0;
}