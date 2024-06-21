#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1;i <= n;i++){
        int m;
        cin >> m;
        arr.emplace_back(i, m);
    }

    for(auto &a : arr){
        if(ans.empty() || ans.back() < a.second) ans.push_back(a.second);
        else{
            auto pos = lower_bound(ans.begin(), ans.end(), a.second);
            *pos = a.second;
        }
    }
    cout << ans.size() << "\n";
    return 0;
}