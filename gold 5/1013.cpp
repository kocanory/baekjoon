#include <iostream>
#include <regex>

using namespace std;

int t;
string s;
regex re("(100+1+|01)+");

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> s;
        cout << (regex_match(s, re) ? "YES" : "NO") << "\n";
    }

    return 0;
}