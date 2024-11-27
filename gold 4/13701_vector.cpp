#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> check((1 << 25) / 32);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        cin >> n;
        if(cin.eof()) break;
        if(!(check[n / 32] & 1 << (n % 32))){
            check[n / 32] += 1 << (n % 32);
            cout << n << " ";
        }
    }
    return 0;
}