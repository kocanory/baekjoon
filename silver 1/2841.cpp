#include <iostream>
#include <vector>

using namespace std;

int n, p, ans = 0;
vector<int> arr[7];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> p;
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        
        if(arr[a].empty() || arr[a].back() < b){
            arr[a].push_back(b);
            ans++;
        }
        else{
            while(!arr[a].empty() && arr[a].back() > b){
                arr[a].pop_back();
                ans++;
            }
            if(arr[a].empty() || arr[a].back() < b){
                arr[a].push_back(b);
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}