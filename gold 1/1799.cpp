#include <iostream>
#include <vector>

using namespace std;

int n;
int ans[2];
vector<int> l(20);
vector<int> r(20);
vector<vector<int>> chess;

void tracking(int row, int col, int count, int color){
    if(col >= n){
        row++;
        if(col % 2 == 0) col = 1;
        else col = 0;
    }

    if(row >= n){
        ans[color] = max(ans[color], count);
        return;
    }

    if(chess[row][col] && !l[col - row + n - 1] && !r[row + col]){
        l[col - row + n - 1] = r[row + col] = 1;
        tracking(row, col + 2, count + 1, color);
        l[col - row + n - 1] = r[row + col] = 0;
    }
    tracking(row, col + 2, count, color);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    chess.assign(n, vector<int>(n));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> chess[i][j];

    tracking(0, 0, 0,0);
    tracking(0, 1, 0, 1);
    cout << ans[0] + ans[1] << "\n";
    return 0;
}
