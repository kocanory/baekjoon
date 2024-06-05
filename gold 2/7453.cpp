#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long answer = 0;
vector<vector<int>> arr;
vector<int> A, B;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.assign(n, vector<int>(4));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 4;j++)
            cin >> arr[i][j];
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) {
            A.push_back(arr[i][0] + arr[j][1]);
            B.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(auto &a : A){
        auto pos1 = lower_bound(B.begin(), B.end(), -a);
        auto pos2 = upper_bound(B.begin(), B.end(), -a);
        answer += (pos2 - pos1);
    }

    cout << answer << "\n";

    return 0;
}