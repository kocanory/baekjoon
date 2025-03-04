#include <iostream>
#include <vector>

using namespace std;

long long a, b, ans = 0;
int MAX = 10000000;
vector<bool> check(MAX + 1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    
    for(int i = 2;i * i <= MAX;i++){
        if(!check[i]){
            for(int j = i * i;j <= MAX;j+=i)
                check[j] = true;
        }
    }
    
    for(int i = 2;i <= MAX;i++){
        if(!check[i]){
            long long num = i;
            while(num <= b / i){
                if(a <= num * i) ans++;
                num *= i;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}