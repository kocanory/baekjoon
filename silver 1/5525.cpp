#include <iostream>
#include <vector>

using namespace std;

int n, m, j = 0, ans = 0;
string s, pattern;
vector<int> table;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s;
    
    for(int i = 0;i < 2 * n + 1;i++){
        if(i % 2) pattern += 'O';
        else pattern += 'I';
    }
    
    table.assign(2 * n + 1, 0);
    for(int i = 1;i < 2 * n + 1;i++){
        while(j != 0 && pattern[i] != pattern[j]) j = table[j - 1];
        if(pattern[i] == pattern[j]) table[i] = ++j;
    }
    
    j = 0;
    for(int i = 0;i < m;i++){
        while(j != 0 && s[i] != pattern[j]) j = table[j - 1];
        if(s[i] == pattern[j]){
            if(j == (2 * n + 1) - 1){
                ans++;
                j = table[j];
            }
            else j++;
        }
    }
    cout << ans << "\n";
    return 0;
}