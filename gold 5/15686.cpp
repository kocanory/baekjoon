#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m, ans = 1e9;
vector<vector<int>> arr;
vector<pair<int, int>> house, shop, temp;

void dfs(int index, int count){
    if(count >= m){
        int sum = 0;
        for(auto &h : house){
            int dist = 1e9;
            for(auto &v : temp) dist = min(dist, abs(v.first - h.first) + abs(v.second - h.second));
            sum += dist;
        }
        ans = min(ans, sum);
        return;
    }
    for(int i = index;i < shop.size();i++){
        temp.push_back(shop[i]);
        dfs(i + 1, count + 1);
        temp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(n));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) house.emplace_back(i, j);
            else if(arr[i][j] == 2) shop.emplace_back(i, j);
        }
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}