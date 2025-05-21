#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int n;
unordered_map<char, bool> check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cin.ignore();
    
    while(n--){
        string str;
        vector<string> words;
        
        getline(cin, str);
        
        stringstream ss(str);
        while(getline(ss, str, ' ')) words.push_back(str);
        
        bool flag = false;
        
        for(auto &w : words){
            if(!check[tolower(w[0])]){
                check[tolower(w[0])] = true;
                flag = true;
                w.insert(1, "]");
                w.insert(0, "[");
                break;
            }
        }
        
        if(!flag){
            for(auto &w : words){
                for(int i = 1;i < w.length();i++){
                    if(!check[tolower(w[i])]){
                        check[tolower(w[i])] = true;
                        flag = true;
                        w.insert(i + 1, "]");
                        w.insert(i, "[");
                        break;
                    }
                }
                if(flag) break;
            }
        }
        
        for(auto &w : words) cout << w + " ";
        cout << "\n";
    }

    return 0;
}