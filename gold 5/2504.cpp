#include <iostream>
#include <stack>

using namespace std;

string s;
stack<char> st;
int ans = 0, mul = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    
    for(int i = 0;i < s.length();i++){
        if(s[i] == '('){
            st.push(s[i]);
            mul *= 2;
        }
        if(s[i] == '['){
            st.push(s[i]);
            mul *= 3;
        }
        if(s[i] == ')'){
            if(st.empty() || st.top() != '('){
                ans = 0;
                break;
            }
            if(s[i - 1] == '('){
                ans += mul;
                mul /= 2;
                st.pop();
            }
            else{
                mul /= 2;
                st.pop();
            }
        }
        if(s[i] == ']'){
            if(st.empty() || st.top() != '['){
                ans = 0;
                break;
            }
            if(s[i - 1] == '['){
                ans += mul;
                mul /= 3;
                st.pop();
            }
            else{
                mul /= 3;
                st.pop();
            }
        }
    }
    if(!st.empty()) ans = 0;
    cout << ans << "\n";
    return 0;
}