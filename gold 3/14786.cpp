#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int a, b, c;
long double low, high;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    low = (c - b) / (double) a, high = (c + b) / (double) a;
    while (high - low >= 1e-9) {
        long double mid = (high + low) / 2;
        long double val = (c - b * sin(mid)) / (double) a;
        if (mid > val) high = mid;
        else low = mid;
    }
    cout << setprecision(10) << low;
}