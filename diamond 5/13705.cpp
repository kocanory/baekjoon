#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef __float128 llf;

int x, y, z, t = 80;
llf a, b, c;
llf low, high, pi = 3.1415926535897932384626Q;

llf sin(llf n) {
    n -= (__int128)(n / (2 * pi)) * (pi * 2);
    llf r = n, num = n, fact = -n * n;
    for (llf d = 2;d < 30;d+=2) {
        r += num *= fact / (d * (d + 1));
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> z;
    a = x, b = y, c = z;

    low = (c - b) / a, high = (c + b) / a;

    while (t--) {
        llf mid = (low + high) / 2, val = a * mid + b * sin(mid);
        if (val > c) high = mid;
        else low = mid;
    }

    cout << setprecision(6) << fixed << (long double)((__int128)(low * (llf)1000000 + (llf)0.5) / (llf)1000000);
}