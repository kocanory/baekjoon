#include <iostream>
#include <vector>
#include <set>

using namespace std;

int r, c, idx = 1, ans = 0;
vector<string> arr;
set<string> word;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;
    arr.assign(r, "");
        
    for(int i = 0;i < r;i++)
        cin >> arr[i];
        
    for(int j = 0;j < c;j++){
        string tmp = "";
        for(int i = 0;i < r;i++)
            tmp += arr[i][j];
        word.insert(tmp);
    }
    
    while(idx < r){
        set<string> check;
        for(auto w : word){
            string tmp = w.substr(idx, r);
            check.insert(tmp);
        }
        
        if(check.size() != c) break;
        
        idx++;
        ans++;
    }
    cout << ans;
    return 0;
}