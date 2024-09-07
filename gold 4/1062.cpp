#include <iostream>
#include <vector>

using namespace std;

int n, k, ans;
vector<string> arr;
vector<bool> alpha(26);

int readNum(){
    bool read;
    int cnt = 0;
    for(auto &a : arr){
        read = true;
        for(auto &c : a){
            if(!alpha[c - 'a']){
                read = false;
                break;
            }
        }
        if(read) cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt){
    if(cnt == k){
        ans = max(ans, readNum());
        return;
    }
    for(int i = idx;i < 26;i++){
        if(alpha[i]) continue;
        alpha[i] = true;
        dfs(i, cnt + 1);
        alpha[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0;i < n;i++){
        string str;
        cin >> str;
        arr.push_back(str);
    }
    if(k < 5){
        cout << 0 << "\n";
        return 0;
    }

    alpha['a' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['c' - 'a'] = true;
    k -= 5;

    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}