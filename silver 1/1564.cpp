#include <iostream>

using namespace std;

int n;
long long t = 1;
string num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n) {
        t *= (n--);
        while (!(t % 10))
            t /= 10;
        t %= (long long)1e12;
    }
    num = to_string(t);
    cout << num.substr(num.size() - 5, 5);
    return 0;
}