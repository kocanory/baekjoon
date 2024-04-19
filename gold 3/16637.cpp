#include <iostream>
#include <climits>

using namespace std;

int n, answer = INT_MIN;
string s;

int calc(int a, int b, char oper){
    int result = a;
    switch(oper){
        case '+' : result += b; break;
        case '-' : result -= b; break;
        case '*' : result *= b; break;
    }
    return result;
}

void dfs(int index, int cur){
    if(index > n - 1){
        answer = max(answer, cur);
        return;
    }
    char oper = (index == 0) ? '+' : s[index - 1];
    
    if(index + 2 < n){
        int bracket = calc(s[index] - '0', s[index + 2] - '0', s[index + 1]);
        dfs(index + 4, calc(cur, bracket, oper));
    }
    dfs(index + 2, calc(cur, s[index] - '0', oper));
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