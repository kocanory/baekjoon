#include <iostream>
#include <map>

using namespace std;

int n;
string s;
map<string, int> cnt;

class Trie {
    map<char, Trie*> child;
    bool check = false;

public:
    void insert(string word) {
        auto now = this;
        for (auto c : word) {
            if (now -> child[c] == NULL) now -> child[c] = new Trie();
                now = now -> child[c];
        }
        now -> check = true;
        cnt[word]++;
    }
    string search(string word) {
        auto now = this;
        string res = "";
        for (auto c : word) {
            res += c;
            if (now -> child[c] == NULL) return res;
            now = now -> child[c];
        }

        if (now -> check)
            res += to_string(cnt[word] + 1);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    Trie* trie = new Trie();
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << trie->search(s) << "\n";
        trie->insert(s);
    }
    delete trie;
    return 0;
}