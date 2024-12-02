#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<pair<int, int>> braket;
vector<bool> selectBracket(10), express(201);
vector<string> ans;

void dfs(int idx, int cnt){
    if(cnt){
        string res = "";
        for(int i = 0;i < str.length();i++)
            if(!express[i])
                res += str[i];
        if(find(ans.begin(), ans.end(), res) == ans.end())
            ans.push_back(res);
    }
    for(int i = idx;i < braket.size();i++){
        if(selectBracket[i]) continue;
        selectBracket[i] = true;
        express[braket[i].first] = true;
        express[braket[i].second] = true;
        dfs(idx + 1, cnt + 1);
        express[braket[i].first] = false;
        express[braket[i].second] = false;
        selectBracket[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str;
    
    vector<int> check;
    for(int i = 0;i < str.length();i++){
        if(str[i] == '(') check.push_back(i);
        else if(str[i] == ')'){
            int b = check.back();
            check.pop_back();
            braket.push_back({b, i});
        }
    }
    dfs(0, 0);
    sort(ans.begin(), ans.end());
    for(auto &a : ans) cout << a << "\n";
    return 0;
}