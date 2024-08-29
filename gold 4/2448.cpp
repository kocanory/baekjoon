#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> arr;

void dfs(int x, int y, int count){
    if(count == 3){
        arr[x][y] = '*';
        arr[x + 1][y - 1] = '*';
        arr[x + 1][y + 1] = '*';
        arr[x + 2][y - 2] = '*';
        arr[x + 2][y - 1] = '*';
        arr[x + 2][y] = '*';
        arr[x + 2][y + 1] = '*';
        arr[x + 2][y + 2] = '*';
    }
    else{
        dfs(x, y, count / 2);
        dfs(x + count / 2, y - count / 2, count / 2);
        dfs(x + count / 2, y + count / 2, count / 2);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, vector<char>(n * 2, ' '));
    dfs(0, n - 1, n);
    for(int i = 0;i < n ;i++){
        for(int j = 0;j < 2 * n - 1;j++)
            cout << arr[i][j];
        cout << "\n";
    }
    return 0;
}