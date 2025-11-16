#include <iostream>

using namespace std;

int a, b, ans = 0;

void dfs(string num){
    if(num.size() != 0){
        if(stoll(num) > b) return;
        if(stoll(num) >= a) ans++;
    }
    dfs("4" + num);
    dfs("7" + num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    dfs("");
    cout << ans;
    return 0;
}