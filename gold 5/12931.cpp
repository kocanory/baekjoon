#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 0;
vector<int> B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    B.assign(n, 0);
    
    for(auto &b : B) cin >> b;
    
    while(true){
        int zero = 0;
        
        for(auto &b : B){
            if(b % 2){
                cnt++;
                b--;
            }
            if(!b)
                zero++;
        }
        
        if(zero == n)
            break;
            
        for(auto &b : B)
            b /= 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}