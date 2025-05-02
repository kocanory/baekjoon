#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int r, c, n, t = 2;
vector<string> arr;
vector<vector<int>> check;

void inst(int t){
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            if(arr[i][j] == '.'){
                arr[i][j] = 'O';
                check[i][j] = t + 3;
            }
}

void dele(int t){
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            if(check[i][j] == t){
                for(int d = 0;d < 4;d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == '.') continue;
                    arr[nx][ny] = '.';
                }
                arr[i][j] = '.';
                check[i][j] = 0;
            }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c >> n;
    arr.assign(r, "");
    check.assign(r, vector<int>(c));
    
    for(int i = 0;i < r;i++){
        cin >> arr[i];
        for(int j = 0;j < c;j++){
            if(arr[i][j] == 'O'){
                check[i][j] = 3;
            }
        }
    }
    
    while(true){
        if(t == n + 1){
            for(int i = 0;i < r;i++)
                cout << arr[i] << "\n";
            break;
        }
        if(t % 2){
            dele(t);
        }
        else{
            inst(t);
        }
        t++;
    }

    return 0;
}