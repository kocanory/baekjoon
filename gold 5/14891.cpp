/******************************************************************************

Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, g, d, ans;
vector<string> gears(4);
vector<int> isRotated(4);

void rotate(int idx, int dir){
    if(dir == 1) gears[idx] = gears[idx].substr(7) + gears[idx].substr(0, 7);
    else if(dir == -1) gears[idx] = gears[idx].substr(1, 7) + gears[idx].substr(0, 1);
}

void leftCheck(int idx, int dir){
    if(idx <= 0) return;
    if(gears[idx][6] != gears[idx - 1][2]){
        isRotated[idx - 1] = -dir;
        leftCheck(idx - 1, -dir);
    }
}

void rightCheck(int idx, int dir){
    if(idx >= 3) return;
    if(gears[idx][2] != gears[idx + 1][6]){
        isRotated[idx + 1] = -dir;
        rightCheck(idx + 1, -dir);
    }
}

void check(int idx, int dir){
    isRotated[idx] = dir;
    leftCheck(idx, dir);
    rightCheck(idx, dir);
    for(int i = 0;i < 4;i++) rotate(i, isRotated[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0;i < 4;i++) cin >> gears[i];

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> g >> d;
        isRotated.assign(4, 0);
        check(g - 1, d);
    }

    for(int i = 0;i < 4;i++) ans += (gears[i][0] - '0') * pow(2, i);
    cout << ans << "\n";
    return 0;
}