#include <iostream>
#include <climits>

using namespace std;

int n, answer = INT_MIN;
string s;

int calc(int a, int b, char op){
    int result = a;
    switch(op){
        case '+': result += b; break;
        case '*': result *= b; break;
        case '-': result -= b; break;
    }
    return result;
}

void dfs(int index, int val){
    if(index > n - 1){
        answer = max(answer, val);
        return;
    }
    char oper = (index == 0) ? '+' : s[index - 1];
    if(index < n - 2){
        int bracket = calc(s[index] - '0', s[index + 2] - '0', s[index + 1]);
        dfs(index + 4, calc(val, bracket, oper));
    }
    dfs(index + 2, calc(val, s[index] - '0', oper));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    dfs(0, 0);
    cout << answer << '\n';
    return 0;
}