#include <iostream>

using namespace std;

long long s = 1, e = 1;
int g;
bool check = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> g;
    
    while(true){
        if(e * e - s * s == g){
            check = true;
            cout << e << "\n";
        }
        if(e - s == 1 && e * e - s * s > g) break;
        if(e * e - s * s > g) s++;
        else e++;
    }
    if(!check) cout << -1 << "\n";
    return 0;
}