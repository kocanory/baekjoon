#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k;
string Max = "0", Min = "9876543210";
vector<char> arr;
vector<bool> check(10);

void dfs(string str, int cnt){
    if(cnt >= k){
        if(stoll(str) > stoll(Max)) Max = str;
        if(stoll(str) < stoll(Min)) Min = str;
        return;
    }
    if(arr[cnt] == '>'){
        for(int i = str.back() - '0' - 1;i >= 0;i--){
            if(!check[i]){
                check[i] = true;
                dfs(str + to_string(i), cnt + 1);
                check[i] = false;
            }
        }
    }
    else{
        for(int i = str.back() - '0' + 1;i < 10;i++){
            if(!check[i]){
                check[i] = true;
                dfs(str + to_string(i), cnt + 1);
                check[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k;
    arr.assign(k, ' ');
    
    for(int i = 0;i < k;i++) cin >> arr[i];
    for(int i = 0;i < 10;i++){
        check[i] = true;
        dfs(to_string(i), 0);
        check[i] = false;
    }
    cout << Max << "\n" << Min;
    return 0;
}