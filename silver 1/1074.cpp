#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, answer = 0;

void dfs(int x, int y, int size){
    if(x == r && y == c){
        cout << answer << "\n";
        return;
    }    
    else if(r < x + size && c < y + size && r >= x && c >= y){
        dfs(x, y, size / 2);
        dfs(x, y + size / 2, size / 2);
        dfs(x + size / 2, y, size / 2);
        dfs(x + size / 2, y + size / 2, size / 2);
    }
    else
        answer += (size * size);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> r >> c;
    dfs(0, 0, pow(2, n) * pow(2, n));
    return 0;
}