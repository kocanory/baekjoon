#include <iostream>
#include <cmath>

using namespace std;

long long n, k, start = 0, nine = 9, digit = 1, result;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    while(k > nine * digit){
        k -= nine * digit;
        start += nine;
        nine *= 10;
        digit++;
    }
    
    result = start + ceil(k / double(digit));
    
    cout << (result > n ? -1 : to_string(result)[(k - 1) % digit] - '0');

    return 0;
}