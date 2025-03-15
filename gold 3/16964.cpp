#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<int, vector<int>> graph;
vector<int> seq, order, path;
vector<bool> check;

bool cmp(int a, int b){
    return order[a] < order[b];
}

void dfs(int now){
    check[now] = true;
    path.push_back(now);
    for(auto &next : graph[now]){
        if(!check[next])
            dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    seq.assign(n, 0);
    order.assign(n + 1, 0);
    check.assign(n + 1, false);
    
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0;i < n;i++){
        cin >> seq[i];
        order[seq[i]] = i;
    }
    
    for(int i = 1;i <= n;i++)
        if(!graph[i].empty())
            sort(graph[i].begin(), graph[i].end(), cmp);
    dfs(1);
    
    for(int i = 0;i < n;i++)
        if(seq[i] != path[i]){
            cout << 0 << "\n";
            return 0;
        }
    cout << 1 << "\n";
    return 0;
}