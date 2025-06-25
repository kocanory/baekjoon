#include <iostream>

using namespace std;

int n;
string s = "moo";

void dfs(int n, int k, int l){
    if(n <= 3){
        cout << s[n - 1];
        exit(0);
    }
    
    int new_len = l * 2 + k + 3;
    if(new_len < n) dfs(n, k + 1, new_len);
    else{
        if(l < n && n <= l + k + 3){
            if(n - l != 1) cout << 'o';
            else cout << 'm';
            exit(0);
        }
        else dfs(n - (l + k + 3), 1, 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dfs(n, 1, 3);
    return 0;
}