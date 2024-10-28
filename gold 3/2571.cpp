#include <iostream>

using namespace std;

int n, ans;
int arr[100][100];

bool Square(int x, int y, int h, int w){
    for(int i = x;i < x + h;i++)
        for(int j = y;j < y + w;j++)
            if(!arr[i][j]) return false;
    return true;
}

bool check(int h, int w){
    for(int i = 0;i <= 100 - h;i++)
        for(int j = 0;j <= 100 - w;j++)
            if(Square(i, j, h, w)) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        for(int i = a;i < a + 10;i++)
            for(int j = b;j < b + 10;j++)
                arr[i][j]++;
    }
    
    for(int i = 1;i <= 100;i++)
        for(int j = 1;j <= 100;j++)
            if(check(i, j)) ans = max(ans, i * j);
    cout << ans << "\n";
    return 0;
}