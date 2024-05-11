#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, string> dict;
unordered_map<string, int> index;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        string name;
        cin >> name;
        dict[i] = name;
        index[name] = i;
    }
    
    for(int i = 0;i < m;i++){
        string s;
        cin >> s;
        if(isdigit(s[0])) cout << dict[stoi(s)] << "\n";
        else cout << index[s] << "\n";
    }

    return 0;
}