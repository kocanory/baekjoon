#include <iostream>
#include <vector>

using namespace std;

int n;
long long e = 0, o = 0, c0 = 0, c1 = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int &a : arr) {
        cin >> a;
        
        if (a % 2) {
            o++;
            c1 += e;
        }
        else {
            e++;
            c0 += o;
        }
    }

    cout << min(c0, c1);
    return 0;
}