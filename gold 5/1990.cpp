#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a, b;

bool isPalindrome(int n){
    string pal = to_string(n);
    reverse(pal.begin(), pal.end());
    return pal == to_string(n);
}

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3;i <= sqrt(n);i++)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    b = min(b, 10000000);
    
    for(int i = a;i <= b;i++)
        if(isPalindrome(i) && isPrime(i))
            cout << i << "\n";
    
    cout << -1;
    return 0;
}