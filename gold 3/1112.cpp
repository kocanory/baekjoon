#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num, form;
    cin >> num >> form;

    string convert = "";
    bool positive;

    if (form < 0 || (num >= 0 && form >= 0)) positive = true;
    else positive = false;

    if (!positive) num = -num;

    while (num) {
        int p = num / form;
        int q = num - p * form;
        
        if (q < 0) {
            p += 1;
            q -= form;
        }
        convert = to_string(q) + convert;
        num = p;
    }

    if (!positive) convert = "-" + convert;
    if (convert.length() == 0)
        cout << 0 << "\n";
    else
        cout << convert << "\n";
    return 0;
}