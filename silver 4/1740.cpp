#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long n, answer = 0;
    cin >> n;
    string num = "";
    while(n > 0)
    {
        num += to_string(n % 2);
        n /= 2;
    }
    
    for(int i = 0;i<num.length();i++)
    {
        unsigned long long temp = 1;
        for(int j = 0;j<i;j++)
            temp *= 3;
        answer += temp * (num[i] - '0');
    }
    cout << answer << endl;
    return 0;
}