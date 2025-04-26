#include <iostream>
#include <vector>

using namespace std;

int q;
string s;
vector<vector<int>> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s >> q;
    arr.assign(26, vector<int>(s.length() + 1));
    
    for(int i = 0;i < s.length();i++)
        arr[s[i] - 'a'][i + 1]++;
        
    for(int i = 0;i < 26;i++)
        for(int j = 2;j <= s.length();j++)
            arr[i][j] += arr[i][j - 1];
            
    while(q--){
        char c;
        int l, r;
        cin >> c >> l >> r;
        cout << arr[c - 'a'][r + 1] - arr[c - 'a'][l] << "\n";
    }

    return 0;
}