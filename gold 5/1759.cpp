#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> arr;

bool check(string str){
    int v_count = 0, c_count = 0;
    for(auto &s : str){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') v_count++;
        else c_count++;
    }
    return v_count >= 1 && c_count >= 2;
}

void dfs(int index, string str){
    if(str.length() >= l){
        if(check(str)) cout << str << "\n";
        return;
    }
    for(int i = index;i < arr.size();i++){
        str += arr[i];
        dfs(i + 1, str);
        str.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> c;
    arr.assign(c, 0);
    for(int i = 0;i < c;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    dfs(0, "");
    return 0;
}