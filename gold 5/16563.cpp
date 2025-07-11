#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, len = 5000000, num;
vector<int> prime(len + 1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 2;i <= len;i++) prime[i] = i;
    
    for(int i = 2;i <= sqrt(len);i++)
        if(prime[i] == i)
            for (int j = i * i;j <= len;j+=i)
                if(prime[j] == j)
                    prime[j] = i;
                    
    while(n--){
        cin >> num;
        while(num > 1){
            cout << prime[num] << " ";
            num /= prime[num];
        }
        cout << "\n";
    }

    return 0;
}