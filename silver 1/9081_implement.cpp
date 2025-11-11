#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;

string next(string w){
    for (int i = w.size() - 1;i > 0;i--){
        if(w[i - 1] < w[i]){
            for(int j = w.size() - 1;j >= i;j--){
                if(w[i - 1] < w[j]){
                    swap(w[i - 1], w[j]);
                    string tmp = w.substr(i, w.size() - i);
                    sort(tmp.begin(), tmp.end());
                    return w.substr(0, i) + tmp;
                }
            }
        }
    }
    return w;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> s;
        cout << next(s) << "\n";
    }
    return 0;
}