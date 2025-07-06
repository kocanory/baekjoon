#include <iostream>

using namespace std;

int n;

void dfs(string str, int cnt){
    int size = str.size();
    for(int i = 1;i <= size / 2;i++)
        if(str.substr(size - i, i) == str.substr(size - 2 * i, i))
            return;
            
    if(cnt == n){
        cout << str;
        exit(0);
    }
    
    dfs(str + "1", cnt + 1);
    dfs(str + "2", cnt + 1);
    dfs(str + "3", cnt + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dfs("", 0);

    return 0;
}