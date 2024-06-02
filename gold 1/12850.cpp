#include <iostream>
#include <vector>

using namespace std;

int n;

vector<vector<long long>> arr = {{0, 1, 1, 0, 0, 0, 0, 0},
                           {1, 0, 1, 1, 0, 0, 0, 0},
                           {1, 1, 0, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 1, 0, 0},
                           {0, 0, 1, 1, 0, 1, 0, 1},
                           {0, 0, 0, 1, 1, 0, 1, 0},
                           {0, 0, 0, 0, 0, 1, 0, 1},
                           {0, 0, 0, 0, 1, 0, 1, 0}};

vector<vector<long long>> multi(vector<vector<long long>> &a, vector<vector<long long>> &b){
    vector<vector<long long>> ret(8, vector<long long>(8));
    for(int i= 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            long long val = 0;
            for(int k = 0;k < 8;k++){
                val += (a[i][k] * b[k][j]);
                val %= 1000000007;
            }
            ret[i][j] = val % 1000000007;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<long long>> answer(8, vector<long long>(8));
    for(int i = 0;i < 8;i++) answer[i][i] = 1;
    vector<vector<long long>> factor = arr;
    while(n){
        if(n & 1){
            answer = multi(answer, factor);
            n--;
        }
        factor = multi(factor, factor);
        n /= 2;
    }
    cout << answer[0][0] << "\n";
    return 0;
}