#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> s;
        if(!next_permutation(s.begin(), s.end()))
            prev_permutation(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}