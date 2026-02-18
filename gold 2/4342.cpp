#include <iostream>

using namespace std;

long long n, m;

bool check(long long a, long long b, bool turn) {
    if (a % b == 0) return turn;
    if (a >= 2 * b) return turn;
    return check(b, a % b, !turn);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        check(max(n, m), min(n, m), true) ? cout << "A wins\n" : cout << "B wins\n";
    }
}