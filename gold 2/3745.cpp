#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n){
        ans.clear();
        int num;
        for(int i = 0; i < n;i++){
            cin >> num;
            if(ans.empty() || ans.back() < num) ans.push_back(num);
            else {
                auto pos = lower_bound(ans.begin(), ans.end(), num);
                *pos = num;
            }
        }
        cout << ans.size() << "\n";
    }
    return 0;
}