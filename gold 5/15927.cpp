#include <iostream>
#include <algorithm>

using namespace std;

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    if(s == rev){
        for(int i = 1;i < s.size();i++)
            if(s[i] != s[i - 1]){
                cout << s.size() - 1;
                exit(0);
            }
        cout << -1;
    }
    else cout << s.size();

    return 0;
}