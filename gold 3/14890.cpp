#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, l, result = 0;
vector<vector<int>> arr1, arr2;

void calc(vector<vector<int>> &arr){
    for(int i = 0 ;i < n;i++){
        vector<bool> slope(n, false);
        bool possible = true;
        for(int h = 0;h < n - 1;h++){
            if(abs(arr[i][h] - arr[i][h + 1]) > 1){
                possible = false;
                break;
            }
            
            if(arr[i][h] == arr[i][h + 1] + 1){
                int cur = arr[i][h + 1];
                for(int k = h + 2; k < h + 1 + l;k++){
                    if(k >= n || arr[i][k] != cur){
                        possible = false;
                        break;
                    }
                }
                if(possible) slope[h + l] = true;
                else break;
            }
            
            if(arr[i][h] == arr[i][h + 1] - 1){
                int cur = arr[i][h];
                for(int k = h;k > h - l;k--){
                    if(k < 0 || arr[i][k] != cur || slope[k]){
                        possible = false;
                        break;
                    }
                }
            }
        }
        if(possible) result++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> l;
    
    arr1.assign(n, vector<int>(n));
    arr2.assign(n, vector<int>(n));
    
    for(int i = 0;i < n;i++){
        for(int j =0;j < n;j++){
            cin >> arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    }
    calc(arr1);
    calc(arr2);
    cout << result << "\n";
    return 0;
}