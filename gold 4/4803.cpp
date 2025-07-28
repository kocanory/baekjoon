#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int t = 1, cnt, n, m, a, b, f;
unordered_map<int, vector<int>> graph;
vector<bool> check;

void dfs(int now, int before){
    check[now] = true;
    for(auto nxt : graph[now]){
        if(!check[nxt]) dfs(nxt, now);
        else if(nxt != before) f = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        
        graph.clear();
        check.assign(n + 1, false);
        cnt = 0;
        
        while(m--){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i = 1;i <= n;i++)
            if(!check[i]){
                f = 1;
                dfs(i, 0);
                cnt += f;
            }
        cout << "Case " << t << ": ";
        if (cnt > 1) cout << "A forest of " << cnt << " trees.\n";
        else if (cnt == 1) cout << "There is one tree.\n";
        else cout << "No trees.\n";
        t++;
    }

    return 0;
}