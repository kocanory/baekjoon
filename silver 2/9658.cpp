#include <iostream>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << (n % 7 == 1 || n % 7 == 3 ? "CY" : "SK");

    return 0;
}