#include <iostream>

using namespace std;

int n;

string solve(){
    if(n == 0) return "0";
    
    string res = "";
    while(n){
        if(n % -2){
            res = "1" + res;
            n = (n - 1) / -2;
        }
        else{
            res = "0" + res;
            n /= -2;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cout << solve() << "\n";
    return 0;
}