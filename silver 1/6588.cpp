#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> check(1000001, true);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 2;i * i <= 1000000;i++)
        for(int j = i * i;j <= 1000000;j += i)
            check[j] = false;
            
    while(true){
        cin >> n;
        if(!n) break;
        for(int i = 2;i <= n / 2;i++)
            if(check[i] && check[n - i]){
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
    }

    return 0;
}