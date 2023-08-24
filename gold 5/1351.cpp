#include <iostream>
#include <map>

using namespace std;

map<long long, long long> m;

long long recursive(long long n, long long p, long long q)
{
    if(m.find(n) != m.end()) return m[n];
    return m[n] = recursive(n / p, p, q) + recursive(n / q, p, q);
}
int main()
{
    long long n, p, q;
    cin >> n >> p >> q;
    m[0] = 1;
    cout << recursive(n, p, q) << endl;
    return 0;
}