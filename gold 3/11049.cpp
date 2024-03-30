#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> matrix;
vector<vector<int>> dp(510, vector<int>(510, INT_MAX));

int mat(int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - i;j++){
            int a = j, b = j + i;
            if(a == b) dp[a][b] = 0;
            else{
                for(int k = a;k < b;k++)
                    dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    matrix.assign(n, vector<int>(2));
    for(int i = 0;i < n;i++)
        cin >> matrix[i][0] >> matrix[i][1];
    cout << mat(n) << "\n";
    return 0;
}