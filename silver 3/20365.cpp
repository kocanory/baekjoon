#include <iostream>

using namespace std;

int n, b = 0, r = 0;
char back = 'A';
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> str;

    for (auto s : str) {
        if (back != s) {
            s == 'B' ? b++ : r++;
            back = s;
        }
    }

    cout << min(b, r) + 1;
    return 0;
}