#include <iostream>
#include <algorithm>

using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> t;

    while(true){
        if(t.back() == 'A'){
            t.pop_back();
        }
        else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        if(s.size() == t.size()){
            if(s == t) cout << 1 << "\n";
            else cout << 0 << "\n";
            break;
        }
    }
    return 0;
}