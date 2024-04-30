#include <iostream>
#include <vector>
#include <map>

using namespace std;

string s;

vector<char> op, operand;
map<char, int> priority;

string convert(string s){
    string res = "";
    for(auto c : s){
        if(c >= 'A' && c <= 'Z' ) res += c;
        else if(c == '(') op.push_back('(');
        else if(c  == ')'){
            while(!op.empty() && op.back() != '(')
            {
                res += op.back();
                op.pop_back();
            }
            op.pop_back();
        }
        else{
            while(!op.empty() && priority[op.back()] >= priority[c]){
                res += op.back();
                op.pop_back();
            }
            op.push_back(c);
        }
    }
    
    while(!op.empty()){
        res += op.back();
        op.pop_back();
    }
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    
    priority['-'] = 1;
    priority['+'] = 1;
    priority['/'] = 2;
    priority['*'] = 2;
    
    cout << convert(s) << "\n";
    return 0;
}