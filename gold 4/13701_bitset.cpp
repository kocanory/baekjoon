#include <iostream>
#include <bitset>

using namespace std;

int n;
bitset<1 << 25> set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        cin >> n;
        if(cin.eof()) break;
        if(!set[n]){
            set[n] = true;
            cout << n << " ";
        }
    }
    return 0;
}