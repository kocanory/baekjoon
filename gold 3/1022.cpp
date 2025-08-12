#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int r1, c1, r2, c2, total, space, x = 0, y = 0, d = 0, c = 1, l = 1;
vector<vector<int>> arr;
vector<pair<int, int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r1 >> c1 >> r2 >> c2;
    arr.assign(r2 - r1 + 1, vector<int>(c2 - c1 + 1));
    total = (r2 - r1 + 1) * (c2 - c1 + 1);

    while (total) {
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < l;j++) {
                if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
                    arr[x - r1][y - c1] = c;
                    total--;
                    space = to_string(c).size();
                }
                c++;
                x += dir[d].first;
                y += dir[d].second;
            }
            d = (d + 1) % 4;
        }
        l++;
    }
    for (int i = 0;i < r2 - r1 + 1;i++) {
        for (int j = 0;j < c2 - c1 + 1;j++) {
            cout << setw(space) << right << arr[i][j] << " ";
        }
        cout << "\n";
    }
}