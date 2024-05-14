#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr(9, vector<int>(9));
vector<vector<bool>> row(9, vector<bool>(9));
vector<vector<bool>> col(9, vector<bool>(9));
vector<vector<bool>> square(9, vector<bool>(9));

void dfs(int count){
    if(count == 81){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++)
                cout << arr[i][j];
            cout << "\n";
        }
        exit(0);
    }
    
    int i = count / 9, j = count % 9;
    if(arr[i][j] == 0){
        for(int num = 1;num <= 9;num++){
            if(!row[i][num] && !col[j][num] && !square[(i / 3) * 3 + j / 3][num]){
                arr[i][j] = num;
                row[i][num] = true;
                col[j][num] = true;
                square[(i / 3) * 3 + j / 3][num] = true;
                dfs(count + 1);
                arr[i][j] = 0;
                row[i][num] = false;
                col[j][num] = false;
                square[(i / 3) * 3 + j / 3][num] = false;
            }
        }
    }
    else dfs(count + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0;i < 9;i++)
    {
        string s;
        cin >> s;
        for(int j = 0;j < 9;j++){
            arr[i][j] = s[j] - '0';
            if(arr[i][j] != 0){
                row[i][arr[i][j]] = true;
                col[j][arr[i][j]] = true;
                square[(i / 3) * 3 + j / 3][arr[i][j]] = true;
            }
        }
    }

    dfs(0);
    return 0;
}