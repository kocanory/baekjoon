#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, a, b;
unordered_map<int, vector<int>> map;
vector<pair<int, int>> level_list;
vector<int> candidate;

void bfs(){
    for(int i = 1;i <= n;i++){
        if(map[i].empty()) continue;
        queue<pair<int, int>> q;
        vector<bool> visited(n + 1);
        int maxlevel = 0;
        
        q.push({i, 0});
        visited[i] = true;
        
        while(!q.empty()){
            auto[now, level] = q.front(); q.pop();
            maxlevel = max(maxlevel, level);
            for(auto next : map[now]){
                if(visited[next]) continue;
                visited[next] = true;
                q.push({next, level + 1});
            }
        }
        level_list.push_back({maxlevel, i});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    while(a != -1 && b != -1){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    bfs();
    sort(level_list.begin(), level_list.end());
    
    for(auto [level, num] : level_list){
        if(level_list[0].first == level)
            candidate.push_back(num);
    }

    cout << level_list[0].first << " " << candidate.size() << "\n";
    for(auto c : candidate)
        cout << c << " ";
    return 0;
}