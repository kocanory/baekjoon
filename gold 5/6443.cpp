#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int t;
string s;
map<char, int> check;

void dfs(string word, string ana){
    if(word.size() == ana.size()){
        cout << ana << "\n";
        return;
    }
    for(auto [k, v] : check){
        if(v){
            check[k]--;
            dfs(word, ana + k);
            check[k]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        check.clear();
        cin >> s;
        sort(s.begin(), s.end());

        for(auto a : s)
            check[a]++;

        dfs(s, "");
    }

    return 0;
}