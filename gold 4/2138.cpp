#include <iostream>

using namespace std;

int n, ans = 1e9;
string s, e, tmp;

void turn(int idx){
    if(idx > 0) tmp[idx - 1] = tmp[idx - 1] == '0' ? '1' : '0';
    tmp[idx] = tmp[idx] == '0' ? '1' : '0';
    if(idx < n - 1) tmp[idx + 1] = tmp[idx + 1] == '0' ? '1' : '0';
}

void solve(int idx){
    tmp = s;
    int cnt = 0;
    
    if(idx == 0){
        tmp[idx] = tmp[idx] == '0' ? '1' : '0';
        tmp[idx + 1] = tmp[idx + 1] == '0' ? '1' : '0';
        cnt++;
    }
    
    for(int i = 1;i < n;i++)
        if(tmp[i - 1] != e[i - 1]){
            turn(i);
            cnt++;
        }
    if(tmp == e) ans = min(ans, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s >> e;
    solve(0);
    solve(1);
    cout << (ans != 1e9 ? ans : -1);
    return 0;
}