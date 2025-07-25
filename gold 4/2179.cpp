#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
string pre = "";
vector<string> arr;
map<string, vector<int>> m;
map<string, bool> check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0;i <n;i++){
        string s, tmp = "";
        cin >> s;
        if(check[s]) continue;
        check[s] = true;
        arr.push_back(s);
        
        for(int j = 0;j < s.size();j++){
            tmp += s[j];
            m[tmp].push_back(i);
            if(m[tmp].size() > 1 && pre.size() <= tmp.size()){
                if ((pre.size() == tmp.size() && m[pre][0] > m[tmp][0]) || pre.size() < tmp.size())
                    pre = tmp;
            }
        }
    }
    cout << arr[m[pre][0]] << "\n" << arr[m[pre][1]];
    return 0;
}