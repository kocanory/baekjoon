#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    int a, b, inter = 0;
    cin >> a >> b;
    for(int i = 0;i<a;i++)
    {
        int input;
        cin >> input;
        m[input]++;
    }

    for(int i = 0;i<b;i++)
    {
        int input;
        cin >> input;
        if(m[input] > 0) inter++;
    }
    cout << a + b - 2 * inter << endl;
    return 0;
}