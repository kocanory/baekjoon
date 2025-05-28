#include <iostream>
#include <vector>

using namespace std;

string a, b;
int ans = -1;
vector<bool> check;

void dfs(string str){
    if(str.size() == a.size()){
        if(stoi(str) < stoi(b))
            ans = max(ans, stoi(str));
        return;
    }
    
    for(int i = 0;i < a.size();i++){
        if(!check[i]){
            if(str.empty() && a[i] == '0') continue;
            check[i] = true;
            dfs(str + a[i]);
            check[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    check.assign(a.size(), false);
    
    dfs("");
    cout << ans;
    return 0;
}