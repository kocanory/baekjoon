#include <iostream>
#include <vector>

using namespace std;

string s;
int n;
vector<bool> check;
vector<int> arr;

void dfs(int idx){
    if(idx == s.size()){
        for(auto a : arr)
            cout << a << " ";
        exit(0);
    }

    string tmp = "";

    for(int i = idx;i <= idx + 1 && i < s.size();i++){
        tmp += s[i];
        int num = stoi(tmp);

        if(num > n || check[num]) continue;

        arr.push_back(num);
        check[num] = true;
        dfs(i + 1);
        check[num] = false;
        arr.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    if(s.size() > 9) n = 9 + (s.size() - 9) / 2;
    else n = s.size();

    check.assign(n + 1, false);

    dfs(0);

    return 0;
}