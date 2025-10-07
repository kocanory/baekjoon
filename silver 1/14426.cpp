#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, cnt = 0;
string str;

struct Trie{
    unordered_map<char, Trie*> child;

    void insert(string s){
        auto now = this;
        for(auto c : s){
            if(now -> child[c] == NULL)
                now -> child[c] = new Trie();
            now = now -> child[c];
        }
    }

    bool find(string s){
        auto now = this;
        for(auto c : s){
            if(now -> child[c] == NULL)
                return false;
            now = now -> child[c];
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    Trie trie;

    while(n--){
        cin >> str;
        trie.insert(str);
    }

    while(m--){
        cin >> str;
        if(trie.find(str))
            cnt++;
    }
    cout << cnt;
    return 0;
}