#include <iostream>
#include <algorithm>

using namespace std;

string s;
int n;

void add(int idx, int num){
    for(int i = idx;i >= 0;i--){
        int tmp = (s[i] - '0') + num;
        if(tmp >= 10){
            num = 1;
            tmp -= 10;
            s[i] = char(tmp + '0');
            if(i == 0) s = '1' + s;
        }
        else{
            s[i] = char(tmp + '0');
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    if(s == rev) {
        add(n - 1, 1);
        n = s.size();
    }
    
    for(int i = n - 1;i >= 0;i--){
        if(s[i] < s[n - 1 - i]) s[i] = s[n - 1 - i];
        else if(s[i] > s[n - 1 - i]){
            add(i, 10 + (s[n - 1 - i] - '0') - (s[i] - '0'));
            i++;
        }
    }
    cout << s;
    return 0;
}