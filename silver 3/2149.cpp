#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string key, encrypt;
    cin >> key;
    cin >> encrypt;
    
    vector<string> arr;
    
    map<char, vector<string>> m;    
    int divide = encrypt.length() / key.length();
    string sorted = key;
    sort(sorted.begin(), sorted.end());
    for(auto a : sorted)
    {
        m[a].push_back(encrypt.substr(0, divide));
        encrypt.erase(0, divide);
    }
    
    for(auto a : key)
        {
            arr.push_back(m[a][0]);
            m[a].erase(m[a].begin());
        }

    for(int j = 0;j<arr[0].length();j++)
        for(int i = 0;i<arr.size();i++)
            cout << arr[i][j];
    return 0;
}