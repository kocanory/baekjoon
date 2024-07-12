#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, e, ans;
vector<int> tap, appliance;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    tap.assign(n, 0);
    appliance.assign(k, 0);
    
    for(int i = 0;i < k;i++) cin >> appliance[i];
    
    for(int i = 0;i < k;i++){
        int a = appliance[i];
        auto empty = find(tap.begin(), tap.end(), 0);
        auto used = find(tap.begin(), tap.end(), a);
        
        if(used != tap.end()) continue;
        if(empty != tap.end()) *empty = a;
        else{
            int max_dist = 0, index = 0;
            for(int j = 0;j < n;j++){
                int dist = find(appliance.begin() + i, appliance.end(), tap[j]) - appliance.begin();
                if(max_dist < dist){
                    max_dist = dist;
                    index = j;
                }
            }
            tap[index] = a;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}