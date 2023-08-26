#include <iostream>

using namespace std;
int fibo[1000010];

int main()
{
    int n, offset = 0;
    cin >> n;
    if(n >= 0)
    {
        fibo[0] = 0;
        fibo[1] = 1;
        for(int i = 2;i<=n;i++)
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000000;
    }
    else
    {
        offset = 1000000;
        fibo[0 + offset] = 0;
        fibo[1 + offset] = 1;
        for(int i = -1 + offset;i>= n + offset;i--)
            fibo[i] = (fibo[i + 2] - fibo[i + 1]) % 1000000000;
    }
    if(fibo[n + offset] > 0)
        {
            cout << 1 << endl;
            cout << fibo[n + offset] % 1000000000 << endl;
        }
    else if(fibo[n + offset] < 0)
        {
            cout << -1 << endl;
            cout << -1 * (fibo[n + offset] % 1000000000) << endl;
        }
    else
        {
            cout << 0 << endl;
            cout << fibo[n + offset] % 1000000000 << endl;
        }
    
    return 0;
}