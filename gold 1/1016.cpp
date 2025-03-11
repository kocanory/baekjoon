#include <iostream>
#include <vector>

using namespace std;

long long Min, Max, cnt = 0;
vector<bool> check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> Min >> Max;
    check.assign(Max - Min + 1, false);
    
    for(long long i = 2;i * i <= Max;i++){
        long long n = Min / (i * i);
        if(Min % (i * i)) n++;
        while(n * i * i <= Max){
            check[n * i * i - Min] = true;
            n++;
        }
    }
    for(int i = 0;i <= Max - Min;i++)
        if(!check[i])
            cnt++;
            
    cout << cnt << "\n";
    return 0;
}