#include <iostream>

using namespace std;

int n, answer = 0;
int dp[10][100][4] = {0, };

int dfs(int num, int idx, int bit){
    int &ret = dp[num][idx][bit];
    if(ret) return ret;
    if(idx >= n){
        if(bit == 3) return 1;
        else return 0;
    }
    if(num < 9){
        ret += dfs(num + 1, idx + 1, bit | ((num + 1 == 9) ? 2 : 0));
        ret %= 1000000000;
    }
    if(num > 0){
        ret += dfs(num - 1, idx + 1, bit | ((num - 1 == 0) ? 1 : 0));
        ret %= 1000000000;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1;i <= 9;i++){
        answer += dfs(i, 1, i == 9 ? 2 : 0);
        answer %= 1000000000;
    }
    cout << answer << "\n";
    return 0;
}