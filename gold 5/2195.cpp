#include <iostream>

using namespace std;

int i = 0, cnt = 0;
string s, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s >> p;
    
    while(i < p.size()){
        int max_len = 0;
        for(int j = 0;j < s.size();j++){
            int tmp = 0;
            while(i + tmp < p.size() && j + tmp < s.size() && p[i + tmp] == s[j + tmp])
                tmp++;
            max_len = max(tmp, max_len);
        }
        i += max_len;
        cnt++;
    }
    cout << cnt;
    return 0;
}