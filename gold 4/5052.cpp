#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int t, n;

bool comp(string &a, string &b){
    return a.length() > b.length();
}

struct trie{
    map<char, trie *> child;
    int count;
    bool end;
    
    trie(){
        count = 0;
        end = false;
    }
    
    void insert(string str){
        trie * now = this;
        for(auto &s : str){
            if(now -> child[s] == NULL) now -> child[s] = new trie();
            now -> child[s] -> count++;
            now = now -> child[s];
        }
        now -> end = true;
    }
    
    bool find(string str){
        trie * now = this;
        for(auto &s : str) now = now -> child[s];
        if(now -> count > 1) return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        vector<string> arr(n);
        for(int i = 0;i < n;i++) cin >> arr[i];
        sort(arr.begin(), arr.end(), comp);
        
        trie *Trie = new trie();
        for(auto &a : arr) Trie -> insert(a);
        
        bool flag = false;
        for(int i = 0;i < n && !flag;i++)
            flag = Trie -> find(arr[i]);
        
        
        if(flag) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }

    return 0;
}