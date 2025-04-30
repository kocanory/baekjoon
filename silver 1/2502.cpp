#include <iostream>
#include <vector>

using namespace std;

int d, k;
vector<int> a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> d >> k;
    a.assign(d + 1, 0);
    b.assign(d + 1, 0);
    
    a[1] = 1, a[2] = 0, b[1] = 0, b[2] = 1;
    
    for(int i = 3;i <= d;i++){
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
    }

    for(int i = 1;i <= k;i++){
        int spare = k - (a[d] * i);
        if(spare % b[d] == 0){
            cout << i << "\n" << spare / b[d];
            break;
        }
    }
    return 0;
}