#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int m, n, ans = 0;
unordered_map<string, int> universe;

void compression(vector<int> v){
    vector<int> tmp = v;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    
    string s = "";
    for(auto a : v){
        int idx = lower_bound(tmp.begin(), tmp.end(), a) - tmp.begin();
        s += to_string(idx);
    }
    universe[s]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;
    
    for(int i = 0;i < m;i++){
        vector<int> tmp(n);
        for(int j = 0;j < n;j++) cin >> tmp[j];
        compression(tmp);
    }

    for(auto [k, v] : universe)
        ans += v * (v - 1) / 2;
        
    cout << ans;
    return 0;
}