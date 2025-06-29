#include <iostream>

using namespace std;

int Min = 1e9, Max = 0;
string num;

int check(string num){
    int cnt = 0;
    for(auto i : num)
        if((i - '0') % 2)
            cnt++;
    return cnt;
}

void dfs(string num, int cnt){
    cnt += check(num);
    if(num.size() == 1){
        Min = min(Min, cnt);
        Max = max(Max, cnt);
        return;
    }
    else if(num.size() == 2)
        dfs(to_string(num[0] - '0' + num[1] - '0'), cnt);
    else{
        for(int i = 1;i < num.size() - 1;i++)
            for(int j = i + 1;j < num.size();j++){
                int f = stoi(num.substr(0, i)), s = stoi(num.substr(i, j - i)), t = stoi(num.substr(j, num.size() - j));
                dfs(to_string(f + s + t), cnt);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    dfs(num, 0);
    cout << Min << " " << Max;
    return 0;
}