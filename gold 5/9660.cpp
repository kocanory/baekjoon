#include <iostream>
#include <vector>

using namespace std;

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    n %= 7;
    if(n == 0 || n == 2)
        cout << "CY" << "\n";
    else cout << "SK" << "\n";
    return 0;
}