#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[101][101];

string add(string a, string b)
{
    string num = "";
    int sum = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int size = max(a.length(), b.length());
    for(int i = 0;i<size || sum ;i++)
    {
        if(a.length() > i) sum += (a[i] - '0');
        if(b.length() > i) sum += (b[i] - '0');
        num += ((sum % 10) + '0');
        sum /= 10;
    }
    reverse(num.begin(), num.end());
    return num;
}

string combination(int n, int m)
{
    if(n == m || m == 0) return "1";
    string &ans = arr[n][m];
    if(ans != "") return arr[n][m];
    ans = add(combination(n-1, m-1), combination(n-1, m));
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    combination(n, m);
    cout << arr[n][m] << endl;
    return 0;
}