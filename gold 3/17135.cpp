#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

int n, m, d, result = 0;
const tuple<int, int> no_target = {-1, -1};
vector<vector<int>> arr;
vector<vector<bool>> isDead;

tuple<int, int> calcTarget(int r, int c){
    for(int i = 1;i <= d;i++){
        for(int dc = -(i-1);dc <= (i - 1);dc++){
            int dr = -(i - abs(dc)), er = r + dr, ec = c + dc;
            if(er < 0 || er >= n || ec < 0 || ec >= m) continue;
            if(arr[er][ec] == 1 && !isDead[er][ec]) return {er, ec};
        }
    }
    return no_target;
}

int simulate(int archer1, int archer2, int archer3){
    int count = 0;
    vector<int> archers = {archer1, archer2, archer3};
    
    isDead.assign(n, vector<bool>(m, false));
    
    for(int i = n;i > 0;i--){
        vector<tuple<int, int>> targets;
        for(auto a : archers) targets.push_back(calcTarget(i, a));
        for(auto t : targets){
            if(t == no_target) continue;
            
            auto[r, c] = t;
            if(!isDead[r][c]) count++;
            isDead[r][c] = true;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> d;
    arr.assign(n, vector<int>(m));
    isDead.assign(n, vector<bool>(m, false));
    
    for(int i = 0;i < n;i++)
        for(int j =0;j < m;j++)
            cin >> arr[i][j];
            
    for(int i = 0;i < m - 2;i++)
        for(int j = i + 1;j < m - 1;j++)
            for(int k = j + 1;k < m;k++)
                result = max(result, simulate(i, j, k));
    
    cout << result << "\n";
    return 0;
}