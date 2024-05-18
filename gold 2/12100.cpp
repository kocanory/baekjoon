#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, answer = 0;
vector<vector<int>> arr;

void shift(int num, vector<vector<int>> &vec){
    queue<int> q;

    switch(num){
        case 0:
            for(int i=0;i < n;i++) {
                for (int j = 0; j < n; j++) {
                    if (vec[i][j]) q.push(vec[i][j]);
                    vec[i][j] = 0;
                }
                int idx = 0;
                while (!q.empty()) {
                    int data = q.front();
                    q.pop();
                    if (vec[i][idx] == 0) vec[i][idx] = data;
                    else if(vec[i][idx] == data){
                        vec[i][idx] *= 2;
                        idx++;
                    }
                    else{
                        idx++;
                        vec[i][idx] = data;
                    }
                }
            }
            break;

        case 1:
            for(int i=0;i < n;i++) {
                for (int j = n - 1; j >= 0; j--) {
                    if (vec[i][j]) q.push(vec[i][j]);
                    vec[i][j] = 0;
                }
                int idx = n - 1;
                while (!q.empty()) {
                    int data = q.front();
                    q.pop();
                    if (vec[i][idx] == 0) vec[i][idx] = data;
                    else if(vec[i][idx] == data){
                        vec[i][idx] *= 2;
                        idx--;
                    }
                    else{
                        idx--;
                        vec[i][idx] = data;
                    }
                }
            }
            break;
        case 2:
            for(int j = 0;j < n;j++){
                for(int i = 0;i < n;i++){
                    if(vec[i][j]) q.push(vec[i][j]);
                    vec[i][j] = 0;
                }
                int idx = 0;
                while(!q.empty()){
                    int data = q.front();q.pop();
                    if(vec[idx][j] == 0) vec[idx][j] = data;
                    else if(vec[idx][j] == data){
                        vec[idx][j] *= 2;
                        idx++;
                    }
                    else
                    {
                        idx++;
                        vec[idx][j] = data;
                    }
                }
            }
            break;

        case 3:
            for(int j = 0;j < n;j++){
                for(int i = n - 1;i >= 0;i--){
                    if(vec[i][j]) q.push(vec[i][j]);
                    vec[i][j] = 0;
                }
                int idx = n - 1;
                while(!q.empty()){
                    int data = q.front();q.pop();
                    if(vec[idx][j] == 0) vec[idx][j] = data;
                    else if(vec[idx][j] == data){
                        vec[idx][j] *= 2;
                        idx--;
                    }
                    else
                    {
                        idx--;
                        vec[idx][j] = data;
                    }
                }
            }
            break;
    }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            answer = max(answer, vec[i][j]);

}

void dfs(int count, vector<vector<int>> vec){
    if(count >= 5) return;

    for(int i = 0;i < 4;i++) {
        vector<vector<int>> temp = vec;
        shift(i, temp);
        dfs(count + 1, temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.assign(n, vector<int>(n));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];

    dfs(0, arr);
    cout << answer << "\n";
}