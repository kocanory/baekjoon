#include <iostream>
#include <vector>

using namespace std;

int n, m, s, e;
vector<vector<int>> graph;
vector<int> d, trace, route;
vector<bool> visited;

int findIdx(){
    int min = 1e9, index;
    for(int i = 1;i <= n;i++){
        if(min > d[i] && !visited[i]){
            index = i;
            min = d[i];
        }
    }
    return index;
}

void dijkstra(){
    for(int i = 1;i <= n;i++){
        d[i] = graph[s][i];
        trace[i] = s;
    }
    
    visited[s] = true;
    
    for(int i = 0;i < n - 2;i++){
        int cur = findIdx();
        visited[cur] = true;
        for(int j = 1;j <= n;j++){
            if(!visited[j]){
                if(d[cur] + graph[cur][j] < d[j]){
                    d[j] = d[cur] + graph[cur][j];
                    trace[j] = cur;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    graph.assign(n + 1, vector<int>(n + 1, 1e9));
    d.assign(n + 1, 1e9);
    trace.assign(n + 1, 1e9);
    visited.assign(n + 1, false);
    
    for(int i = 0;i < m;i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        graph[x][y] = min(graph[x][y], cost);
    }
    
    cin >> s >> e;
    dijkstra();
    cout << d[e] << "\n";
    
    route.push_back(e);
    for(int i = e;i != s;){
        route.push_back(trace[i]);
        i = trace[i];
    }
    
    cout << route.size() << "\n";
    
    for(int i = route.size() - 1;i >= 0;i--)
        cout << route[i] << " ";
    return 0;
}