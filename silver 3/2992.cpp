#include <iostream>

using namespace std;

int n, i, j;
string num;

string check() {
    i = n - 1;
    while (i > 0 && num[i - 1] >= num[i])
        i--;

    if (i == 0) return "0";

    j = n - 1;
    while (num[i - 1] >= num[j]) j--;

    swap(num[i - 1], num[j]);

    j = n - 1;
    while (i < j) {
        swap(num[i], num[j]);
        i++; j--;
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    n = num.size();

    cout << check();
    return 0;
}