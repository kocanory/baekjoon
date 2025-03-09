#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3;i <= sqrt(n);i += 2)
        if(n % i == 0) return false;
    return true;
}

int solve(int n){
    if(n > 2 && n % 2 == 0) n++;
    while(true){
        string palindrome = to_string(n);
        reverse(palindrome.begin(), palindrome.end());
        if(palindrome == to_string(n))
            if(isPrime(n))
                return n;
        if(n < 3) n++;
        else n += 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}