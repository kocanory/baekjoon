#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m, s, e;
vector<vector<int>> graph;
vector<int> d, route, trace;
vector<bool> visited;

int getIndex(){
    int min = INT_MAX;
    int index = 0;
    for(int i = 1;i <= n;i++){
        if(d[i] < min && !visited[i]){
            index = i;
            min = d[i];
        }
    }
    return index;
}

void dijkstra(){
    for(int i = 1;i <= n;i++){
        d[i] = graph[s][i];
        route[i] = s;
    }
    visited[s] = true;
    
    for(int i = 0;i < n - 2;i++){
        int cur = getIndex();
        visited[cur] = true;
        for(int j = 1;j <= n;j++){
            if(!visited[j]){
                if(d[cur] + graph[cur][j] < d[j]){
                    route[j] = cur;
                    d[j] = d[cur] + graph[cur][j];
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
    visited.assign(n + 1, false);
    route.assign(n + 1, -1);
    
    for(int i = 0;i < m;i++){
        int x, y, cost;
        cin >> x >> y;
        cin >> cost;
        graph[x][y] = min(graph[x][y], cost);
    }
    
    cin >> s >> e;
    
    dijkstra();
    cout << d[e] << "\n";
    
    trace.push_back(e);
    for(int i = e;i != s;){
        trace.push_back(route[i]);
        i = route[i];
    }
    cout << trace.size() << "\n";
    for(int i = trace.size() - 1;i >= 0;i--)
        cout << trace[i] << " ";
    return 0;
}