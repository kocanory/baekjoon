#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, button, cnt;
vector<bool> unabled(10, false);

bool check(int n){
    string str = to_string(n);
    for(auto &s : str)
        if(unabled[s - '0']) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cin >> m;
    
    for(int i = 0;i < m;i++){
        cin >> button;
        unabled[button] = true;
    }
    
    cnt = abs(100 - n);
    
    for(int i = 0;i < 1000000;i++){
        if(check(i)){
            int s_cnt = abs(i - n) + to_string(i).length();
            cnt = min(cnt, s_cnt);
        }
    }
    cout << cnt << "\n";
    return 0;
}