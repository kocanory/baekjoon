#include <iostream>

using namespace std;

string l, r;
int m = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> l >> r;
    
    if(l.length() == r.length()){
        for(int i = 0;i < l.length();i++){
            if(l[i] != r[i]) break;
            if(l[i] == '8') m++;
        }
    }

    cout << m;
    return 0;
}