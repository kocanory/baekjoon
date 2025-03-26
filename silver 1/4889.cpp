#include <iostream>
#include <vector>

using namespace std;

int t = 0, cnt = 0;
string s;
vector<char> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        t++;
        cnt = 0;
        st.clear();
        
        cin >> s;
        if(s[0] == '-') break;
        for(auto c : s){
            if(c == '}' && !st.empty() && st.back() == '{') st.pop_back();
            else st.push_back(c);
        }
        
        while(!st.empty()){
            char c1 = st.back(); st.pop_back();
            char c2 = st.back(); st.pop_back();
            if(c1 == c2) cnt++;
            else cnt += 2;
        }
        cout << t << ". " << cnt << "\n";
    }

    return 0;
}