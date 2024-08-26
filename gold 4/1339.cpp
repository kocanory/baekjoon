#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<char, int> word;
unordered_map<char, bool> visited;
set<char> alpha;

int n, ans = 0;
string str;

void dfs(int count, int sum, int idx){
    if(count >= alpha.size()){
        ans = max(ans, sum);
        return;
    }
    for(auto &a : alpha){
        if(!visited[a]){
            visited[a] = true;
            dfs(count + 1, sum + word[a] * idx, idx - 1);
            visited[a] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> str;
        for(int j = 0;j < str.length();j++){
            word[str[str.length() - j - 1]] += pow(10, j);
            alpha.insert(str[str.length() - j - 1]);
        }
    }
    dfs(0, 0, 9);
    cout << ans << "\n";
    return 0;
}