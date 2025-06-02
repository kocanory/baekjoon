#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int t, k;
string w;
unordered_map<char, vector<int>> map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> w >> k;
        map.clear();
        int Min = 10000, Max = 0;
        
        for(int i = 0;i < w.size();i++)
            map[w[i]].push_back(i);
        
        for(auto [key, val] : map){
            if(val.size() >= k){
                for(int i = 0;i < val.size() - k + 1;i++){
                    Min = min(Min, val[i + k - 1] - val[i] + 1);
                    Max = max(Max, val[i + k - 1] - val[i] + 1);
                }
            }
        }
        
        if(Min == 10000 || Max == 0) cout << -1 << "\n";
        else cout << Min << " " << Max << "\n";
    }

    return 0;
}