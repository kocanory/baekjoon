#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, k;
struct Trie{
    map<string, Trie*> m;
    void insert(vector<string> &arr){
        Trie * now = this;
        for(auto a : arr){
            if(now -> m.find(a) == now -> m.end())
                now -> m[a] = new Trie;
            now = now -> m[a];
        }
    }
    void dfs(int idx){
        for(auto a : m){
            for(int i =0;i < idx;i++)
                cout << "--";
            cout << a.first << "\n";
            a.second -> dfs(idx + 1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Trie * t = new Trie;
    cin >> n;
    while(n--){
        cin >> k;
        vector<string> arr(k);
        for(int i =0 ;i < k;i++) cin >> arr[i];
        t -> insert(arr);
    }
    t -> dfs(0);
    return 0;
}