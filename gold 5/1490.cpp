#include <iostream>

using namespace std;
int digit[10];
void get_digit(long long n)
{
    while(n > 0)
    {
        digit[n % 10] = 1;
        n /= 10;
    }
}
int gcd(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while(b > 0)
    {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}
int main()
{
    long long n;
    cin >> n;
    int lcm = 1, loop = 1;
    get_digit(n);
    for(int i = 1;i<10;i++)
        if(digit[i])
            lcm = lcm * i / gcd(lcm, i);
    
    while(true)
    {
        for(int i = 0;i<loop;i++)
            if((n * loop + i) % lcm == 0)
            {
                cout << n * loop + i << endl;
                return 0;
            }
        loop *= 10;
    }
    return 0;
}