#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9, cnt = 0;
bool flag = false;
string s;

void init(){
    flag = false;
    ans = min(ans, cnt);
    cnt = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    for(int i = 0;i < n;i++){
        if(s[i] == 'B') flag = true;
        if(flag && s[i] == 'R') cnt++;
    }
    init();
    
    for(int i = n - 1;i >= 0;i--){
        if(s[i] == 'B') flag = true;
        if(flag && s[i] == 'R') cnt++;
    }
    init();
    
    for(int i = 0;i < n;i++){
        if(s[i] == 'R') flag = true;
        if(flag && s[i] == 'B') cnt++;
    }
    init();
    
    for(int i = n - 1;i >= 0;i--){
        if(s[i] == 'R') flag = true;
        if(flag && s[i] == 'B') cnt++;
    }
    init();
    
    cout << ans;
    return 0;
}