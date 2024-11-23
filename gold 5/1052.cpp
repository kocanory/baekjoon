#include <iostream>

using namespace std;

int n, k;

int findCount(int num){
    int cnt = 0;
    while(num){
        if(num % 2) cnt++;
        num /= 2;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i = 0;;i++){
        if(findCount(n++) <= k){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}